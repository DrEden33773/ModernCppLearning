/**
 * @file TempVarInIf.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief show that you could define a temp variable in `if` statements
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

struct TempVarInIf {
    static void example() {
        std::vector<int> vec = { 1, 2, 3, 4 };

        if (auto itr = std::find(vec.begin(), vec.end(), 3);
            itr != vec.end()) {
            *itr = 4;
        }

        if (auto itr = std::find(vec.begin(), vec.end(), 2);
            itr != vec.end()) {
            *itr = 3;
        }

        for (auto& element : vec) {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }
};