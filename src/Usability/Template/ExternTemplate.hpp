/**
 * @file ExternTemplate.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief show the function of extern template
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../../ToInclude.h"

template class std::vector<int>;
template class std::vector<float>;
extern template class std::vector<std::string>;
extern template class std::vector<bool>;

struct ExternTemplate {
    static void example() {
        std::vector<int> intVector            = { 1, 2, 3 };
        std::vector<float> floatVector        = { 1.0, 2.1, 3.2 };
        std::vector<std::string> stringVector = { "a", "b", "c" }; // not recommended
    }
};