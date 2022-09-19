/**
 * @file VariadicTemplate.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief VariadicTemplate
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class VariadicTemplate {

    template <typename T, typename... Ar>
    void showInputVar(T&& first, Ar&&... rest) {
        std::cout << first << " ";
        if constexpr (sizeof...(rest) > 0) {
            showInputVar(rest...);
        }
    }

    template <typename T, typename... Ar>
    void showInputVar(T& first, Ar&... rest) {
        std::cout << first << " ";
        if constexpr (sizeof...(rest) > 0) {
            showInputVar(rest...);
        }
    }

    template <typename T, typename... Ar>
    void showInputVar_another(T& first, Ar&... rest) {
        std::cout << first << " ";
        showInputVar_another(rest...);
    }
    template <typename T>
    void showInputVar_another(T& only) {
        std::cout << only << " ";
    }

    template <typename T, typename... Ar>
    void showInputVar_another(T&& first, Ar&&... rest) {
        std::cout << first << " ";
        showInputVar_another(rest...);
    }
    template <typename T>
    void showInputVar_another(T&& only) {
        std::cout << only << " ";
    }

public:
    static void example() {
        VariadicTemplate TestObj;

        TestObj.showInputVar(12, 2.3, "fas", 'a'); // will call right_reference method
        std::cout << std::endl;

        TestObj.showInputVar_another(12, 2.3, "fas", 'a'); // will call right_reference method
        std::cout << std::endl;

        int first         = 12;
        float second      = 2.3;
        std::string third = "fas";
        char fourth       = 'a';

        TestObj.showInputVar(first, second, third, fourth); // will call left_reference method
        std::cout << std::endl;

        TestObj.showInputVar_another(first, second, third, fourth); // will call left_reference method
        std::cout << std::endl;
    }
};