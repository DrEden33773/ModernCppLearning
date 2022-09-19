/**
 * @file StructureBind.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief show the function of structure binding
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

struct StructureBind {
    static void example() {
        // lambda expression
        auto f = []() -> std::tuple<int, double, std::string> {
            return std::make_tuple(1, 2.3, "456");
        };
        auto [x, y, z] = f(); // bind
        std::cout << x << ", " << y << ", " << z << std::endl;
        std::cout << std::endl;
    }
};