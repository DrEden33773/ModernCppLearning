/// @brief nullptr

#include <iostream>
#include <memory>
#include <type_traits>

struct NullptrEG {
    NullptrEG() {
        std::cout << "Created a NullptrEG object" << std::endl;
        std::cout << std::endl;
    }
    ~NullptrEG() {
        std::cout << "Destructed a NullptrEG object" << std::endl;
        std::cout << std::endl;
    }
    void foo(char*) {
        std::cout << "foo(char*) is called" << std::endl;
    }
    void foo(int i) {
        std::cout << "foo(int) is called" << std::endl;
    }
    static void example() {
        NullptrEG TestObj;

        if (std::is_same<decltype(NULL), decltype(0)>::value) {
            std::cout << "NULL == 0" << std::endl;
        }
        if (std::is_same<decltype(NULL), decltype(reinterpret_cast<void*>(0))>::value) {
            std::cout << "NULL == (void *)0" << std::endl;
        }
        if (std::is_same<decltype(NULL), std::nullptr_t>::value) {
            std::cout << "NULL == nullptr" << std::endl;
        }

        TestObj.foo(0); // call foo(int)
        // TestObj.foo(NULL);    // Call to member function `foo` is ambiguous
        TestObj.foo(nullptr); // call foo(char*)
    }
};