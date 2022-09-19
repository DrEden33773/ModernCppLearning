# Note of ModernCppLearning

## 1. RightValue Reference

(1) => if a param is Rvalue_Ref, it's legal to give a Lvalue_Ref to it.

```cpp
void f(int&& i) { 
    std::cout << i << std::endl; 
}
int main() {
    int i = 0;
    f(i); // legal
}
```

So, we'd better to replace _LvalueRef_ Param with _RvalueRef_ Param and
