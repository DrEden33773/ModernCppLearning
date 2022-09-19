/**
 * @file ExampleCaller.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief an caller of all examples
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

// #include "Usability/Constant/Nullptr.hpp"
#include "Usability/Template/VariadicTemplate.hpp"
#include "Usability/Variable/InitList.hpp"

namespace ModernCppLearning {

inline void Call_InitList() {
    InitList::example();
    std::cout << std::endl;
}

inline void Call_VariadicTemplate() {
    VariadicTemplate::example();
    std::cout << std::endl;
}

void ExampleCaller() {
    Call_InitList();
    Call_VariadicTemplate();

    std::cout << "Successfully called all examples!" << std::endl;
}

} // namespace ModernCppLearning