/**
 * @file FoldExpression.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief FoldExpression
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class FoldExpression {
private:
    template <typename... T>
    auto sum(T&&... t) {
        std::cout << "called `r_reference` func." << std::endl;
        return (t + ...);
    }

    template <typename... T>
    auto sum(T&... t) {
        std::cout << "called `l_reference` func." << std::endl;
        return (t + ...);
    }

public:
    static void example() {
        FoldExpression TestObj;

        // call r_ref method
        auto result1 = TestObj.sum(1, 2.0, 3.1);
        std::cout << "1 + 2.0 + 3.1 = " << result1;
        std::cout << std::endl
                  << std::endl;

        int a   = 1;
        float b = 2.0;
        float c = 3.1;

        // call l_ref method
        auto result2 = TestObj.sum(a, b, c);
        std::cout << "a(1) + b(2.0) + c(3.1) = " << result2;
        std::cout << std::endl
                  << std::endl;

        // call r_ref method
        auto result3 = TestObj.sum(a, b, 3.1);
        std::cout << "a(1) + b(2.0) + 3.1 = " << result3;
        std::cout << std::endl
                  << std::endl;
    }
};