/**
 * @file InheritanceConstruct.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief InheritanceConstruct
 * @version 0.1
 * @date 2022-09-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../../ToInclude.h"

class InheritanceConstruct {
private:
    class Base {
    public:
        int value1;
        int value2;
        Base() {
            value1 = 1;
        }
        explicit Base(int value)
            : Base() { // delegate Base() constructor
            value2 = value;
        }
        void showNum() {
            std::cout << "value1 = " << value1 << std::endl;
            std::cout << "value2 = " << value2 << std::endl;
            std::cout << std::endl;
        }
    };
    class Subclass : public Base {
    public:
        using Base::Base; // inheritance constructor

        // here is the old writing style =>
        //
        // explicit Subclass(int value)
        //     : Base(value) { }
    };

public:
    static void example() {
        Subclass TestObject { 3 };
        TestObject.showNum();
    }
};