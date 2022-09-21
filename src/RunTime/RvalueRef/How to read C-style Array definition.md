# How to read _C-style_ Array _Definition_

## What is _C-style_ Array look like?

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

4. 如果遇到了括号，跳出一层括号，把括号里面的声明放到`相对更靠外的一层`（例如 `int (*p)[6]`，把*放到最外层，就是`指向int[6]这种数组的指针`，也叫做`数组指针（指向数组的指针）`）

5. 反复重复上述过程

## ATTENTION

数组的本质，就是指针！
