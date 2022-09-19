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
#include "Usability/Practice/ImplFunc.hpp"
#include "Usability/Template/FoldExpression.hpp"
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
inline void Call_FoldExpression() {
    FoldExpression::example();
    std::cout << std::endl;
}
inline void Call_UsabilityPractice_ImplFunc() {
    ImplFunc::example();
    std::cout << std::endl;
}
inline void _success_() {
    std::cout << "Successfully called all examples!" << std::endl;
}

void ExampleCaller() {
    Call_InitList();
    Call_VariadicTemplate();
    Call_FoldExpression();
    Call_UsabilityPractice_ImplFunc();

    _success_();
}

} // namespace ModernCppLearning