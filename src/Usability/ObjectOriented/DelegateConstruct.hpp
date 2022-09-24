/**
 * @file DelegateConstruct.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief DelegateConstruct
 * @version 0.1
 * @date 2022-09-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../../ToInclude.h"

class DelegateConstruct {
private:
    class TestClass {
    private:
        bool ifBasicConstructed   = false;
        bool ifAdvanceConstructed = false;

    public:
        TestClass() {
            ifBasicConstructed = true;
        }
        explicit TestClass(auto& input) // we don't mind the type of input param
            : TestClass() {
            ifAdvanceConstructed = true;
        }
        explicit TestClass(auto&& input) // we don't mind the type of input param
            : TestClass() {
            ifAdvanceConstructed = true;
        }
        void showStatus() {
            std::cout << std::boolalpha;
            std::cout << "ifBasicConstructed   = " << ifBasicConstructed << std::endl;
            std::cout << "ifAdvanceConstructed = " << ifAdvanceConstructed << std::endl;
            std::cout << std::endl;
        }
    };

public:
    static void example() {
        TestClass TestObj1;
        TestObj1.showStatus();
        TestClass TestObj2("AA");
        TestObj2.showStatus();
        // TestClass TestObj3(123); => This is OK
        // TestObj3.showStatus();
    }
};