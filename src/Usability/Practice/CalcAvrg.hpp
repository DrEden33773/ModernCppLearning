/**
 * @file CalcAvrg.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Calculate the average of all inputs
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class CalcAvrg {
private:
    template <typename... Ar>
    auto getAverage(Ar&&... Args) const /* -> decltype((Args + ...) / sizeof...(Args)) */
    {                                   // return type could be automatically determined by compiler
        return ((Args + ...) / sizeof...(Args));
    }

public:
    static void example() {
        CalcAvrg TestObj;
        std::cout << TestObj.getAverage(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << std::endl;
    }
};