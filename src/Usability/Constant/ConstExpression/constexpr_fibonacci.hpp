/**
 * @file constexpr_fibonacci.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief fibonacci, but boosted by `constexpr`
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../../../ToInclude.h"

struct constexpr_fibonacci {
    constexpr int fibonacci(const int n) {
        return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
    }
    constexpr int fibonacci_another(const int n) {
        if (n == 1 || n == 2) {
            return 1;
        } else {
            return fibonacci_another(n - 1) + fibonacci_another(n);
        }
    }
    static void example() {
        constexpr_fibonacci TestObj;
        std::cout << "fibonacci arr's 8th element => "
                  << TestObj.fibonacci(8)
                  << TestObj.fibonacci_another(8)
                  << std::endl;
    }
};