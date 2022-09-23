/**
 * @file InitList.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief show the usage of InitList
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../../ToInclude.h"

struct InitList {
    class MagicFoo {
    public:
        std::vector<int> vec;
        MagicFoo(std::initializer_list<int>&& list) {
            // attention! all elements in the initializer_list is `const`
            for (auto it : list) {
                vec.push_back(it);
            }
        }
    };
    static void example() {
        MagicFoo magicFoo { 1, 2, 3, 4, 5 };

        std::cout << "magicFoo { 1, 2, 3, 4, 5 } => ";
        for (auto it : magicFoo.vec) {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        MagicFoo magicFoo2 = { 1, 2, 3, 4, 5 };

        std::cout << "magicFoo = { 1, 2, 3, 4, 5 } => ";
        for (auto it : magicFoo.vec) {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        MagicFoo magicFoo3({ 1, 2, 3, 4, 5 });

        std::cout << "magicFoo({ 1, 2, 3, 4, 5 }) => ";
        for (auto it : magicFoo.vec) {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        std::cout << std::endl;
    }
};