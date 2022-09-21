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

class Definations {
private:
    void pvalue_def() {
        // left_constChar_arr
        // => the reference of a `const char[6]` array
        const char(&constChar_arr_ref)[6] = "01234";

        // left_int_arr
        // => the reference of a `const int[6]` array
        const int(&int_arr_ref)[6] = { 1, 2, 3, 4, 5, 6 };
    }
};