/**
 * @file Definations.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Try to show the definitions of lvalue, rvalue, pvalue, xvalue
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

class Definations {
private:
    void pvalue_def() {
        // 正确，"01234" 类型为 const char [6]，因此是左值
        const char(&left)[6] = "01234";

        // 断言正确，确实是 const char [6] 类型，
        // 注意 decltype(expr) 在 expr 是左值 且非 无括号包裹的 id 表达式与类成员表达式 时，会返回左值引用
        static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value);

        // 错误，"01234" 是左值，不可被右值引用
        // const char(&&right)[6] = "01234";

        const int(&&right)[4] = { 0, 1, 2, 3 };
        // const int(&right)[4] = { 0, 1, 2, 3 };

        static_assert(std::is_same<decltype(right), const int(&&)[4]>::value);
    }

    void array_invisible_transform() {
        printf("First example => \n");

        const char* const_ptr_to_string                = "test";
        const char*&& const_ptr_to_string_transTo_Rref = "test";

        printf("Called => const char* ptr_to_string = \"test\"; \n");
        printf("Called => const char*&& ptr_to_string_transTo_Rref = \"test\"; \n");

        auto varA = const_ptr_to_string;
        auto varB = const_ptr_to_string_transTo_Rref;

        using typeA = decltype(varA);
        using typeB = decltype(varB);

        if (std::is_same<typeA, typeB>::value) {
            printf("{ptr_to_string} and {ptr_to_string_transTo_Rref} has same type\n");
        } else {
            printf("{ptr_to_string} and {ptr_to_string_transTo_Rref} has different type\n");
        }

        printf("Second example => \n");

        const int tmpIntArr[]                   = { 0, 1, 2 };
        const int* ptr_to_intArr                = tmpIntArr;
        const int*&& ptr_to_intArr_transTo_Rref = tmpIntArr;

        printf("Called => int tmpIntArr[]                   = { 0, 1, 2 }; \n");
        printf("Called => int* ptr_to_intArr                = tmpIntArr; \n");
        printf("Called => int*&& ptr_to_intArr_transTo_Rref = tmpIntArr; \n");

        auto varC = ptr_to_intArr;
        auto varD = ptr_to_intArr_transTo_Rref;

        using typeC = decltype(varC);
        using typeD = decltype(varD);

        if (std::is_same<typeC, typeD>::value) {
            printf("{ptr_to_intArr} and {ptr_to_intArr_transTo_Rref} has same type\n");
        } else {
            printf("{ptr_to_intArr} and {ptr_to_intArr_transTo_Rref} has different type\n");
        }
    }

    void xvalue_example() {
        std::function<std::vector<int>()> giveIntVec
            = []() -> std::vector<int> {
            printf("A vec has been created! \n");
            std::vector<int> res = { 0, 1, 2, 3 };
            printf("If I try to return a vec, then the returned value is `xvalue` \n");
            return res;
        };
        auto received = giveIntVec();
    }
};