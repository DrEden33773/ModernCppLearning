/**
 * @file NonTypeParamDeduction.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief NonTypeParamDeduction
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class NonTypeParamDeduction {
private:
    template <typename T, const int BufSize = 4> // default value for BufSize
    class buffer_t {
    public:
        T& alloc();
        void free(T& item);

    private:
        std::unique_ptr<T[]> data = std::make_unique<T[]>(BufSize);
    };
};