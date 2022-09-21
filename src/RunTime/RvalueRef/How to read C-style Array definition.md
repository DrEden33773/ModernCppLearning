# How to read _C-style_ Array _Definition_

## What does _C-style_ Array look like?

```cpp
int a[10];

const char (&constChar_arr_ref)[6] = "01234";

const int (&int_arr_ref)[6] = { 1, 2, 3, 4, 5, 6 };

const char (*constChar_arr_ptr)[6] = &"01234";

const int (*int_arr_ptr)[6] = &{ 1, 2, 3, 4, 5, 6 };

char *charPtr_arr[3] = { 
    new char(1), 
    new char(2), 
    new char(3), 
};

int *intPtr_arr[6] = { 
    new int(1), 
    new int(2), 
    new int(3), 
};
```

## How should we read _C-style_ Array's _Definition_ ?

1. 找到变量名，如果没有变量名，就找到最里面的结构

2. 向右看，读出你看到的东西（例如，`[]`代表`数组`），但是不要跳出括号

3. 再向左看，读出你看到的东西（例如，`int *`代表`指向int的指针`），但是也不要跳出括号

4. 如果遇到了括号，`用掉`这层括号，把括号里面的声明放到`相对更靠外的一层`（例如 `int (*p)[6]`，把*（`指向...的指针`）放到最外层，就是`指向int[6]这种数组的指针`，也叫做`数组指针（指向数组的指针）`）

5. 反复重复上述过程

## ATTENTION

数组的本质，就是指针！

## DLC1 => function pointer

```cpp
// example 1
int add(int a, int b) { return a + b; }
int (*functionPtr)(int, int); // int (*functionPtr)(int a, int b) = &add;
functionPtr = &add;

int main() {
    return functionPtr(1, 2);
}
```

```cpp
// example 2
void (*p)();
void test() { printf("test\n"); }
p = &test;

int main() {
    p();
    return 0;
}
```

## DLC2 => something about `const`

先看看`const`对于`值变量`的限制作用

```cpp
const int a = 1;
int const b = 1;
```

两种方式都是合法的，都声明了一个`const int`（不可变的常量），但是第一种方式更常用

再看看`const`对于`指针变量`的限制作用

```cpp
int const *a = &1;       // line 1
int *const b = &2;       // line 2
const int *c = &3;       // line 3
const int *const d = &4; // line 4
```

这四种方式都是合法的，只不过，略有不同

无论如何都要记住一个原则：`const`放在`*`的左边，就是`指向const的指针`，放在`*`的右边，就是`const指针（不可变的指针）`

解决了这些疑问，我们就可以对上面四行代码进行分析了

### 第一行

```cpp
int const *a = &1;       // line 1
```

`a`是指针，`const`在`*`左边，指针可变，指针指向的值不可变

```cpp
a = &2; // legal
*a = 3; // illegal
```

### 第二行

```cpp
int *const b = &2;       // line 2
```

`b`是指针，`const`在`*`右边，指针不可变，指针指向的值可变

```cpp
b = &3; // illegal
*b = 4; // legal
```

### 第三行

```cpp
const int *c = &3;       // line 3
```

`c`是指针，`const`在`*`左边，指针可变，指针指向的值不可变

```cpp
c = &4; // legal
*c = 5; // illegal
```

### 第四行

```cpp
const int *const d = &4; // line 4
```

`d`是指针，`const`在`*`左边和右边都有，指针不可变，指针指向的值不可变

```cpp
d = &5; // illegal
*d = 6; // illegal
```

## Practice

```cpp
int (*(*v)[])();
```

## Answer

1. 找到v
2. 有括号 => `v是一个指针`
3. 用掉了括号，所以往右看 => `v这个指针，指向一个数组`
4. 向左看 => `这个数组，里面的元素是指针`
5. 到达更外面的括号，用掉这个括号，然后向右看 => `这个指针，指向一个函数(没有参数)`
6. 向左看，结束 => `这个函数，返回一个int`
7. 总结 => `v是一个指针，指向一个数组，数组里面的元素是指针，指向一个函数，函数会返回int值`

## Legal example of the practice

```cpp
int funcA() { return 1; }
int funcB() { return 2; }

int (*(*v)[])();
int (*funcPtr)() arr[] = { &funcA, &funcB };
v = &arr;

int main() {
    int left  = (*v)[0]() + (*v)[1];
    int right = 3;
    if ( left != right ) {
        exit(-1);
    }
    printf("success!\n");
    return 0;
}
```

这个程序最终的结果是`在控制台上输出 success!`
