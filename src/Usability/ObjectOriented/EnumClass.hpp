/**
 * @file EnumClass.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief EnumClass
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class EnumClass {
private:
    enum class new_enum : unsigned int {
        value1 = 0,
        value2 = 50,
        value3 = 100,
        value4 = 100,
    };

    template <typename T>
    friend std::ostream& operator<<(
        typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream,
        const T& e
    ) {
        stream << static_cast<typename std::underlying_type<T>::type>(e);
        return stream;
    }

public:
    static void example() {
        std::cout << "new_enum::value1 => " << new_enum::value1 << std::endl;
        std::cout << "new_enum::value2 => " << new_enum::value2 << std::endl;
        std::cout << "new_enum::value3 => " << new_enum::value3 << std::endl;
        std::cout << "new_enum::value4 => " << new_enum::value4 << std::endl;
        if (new_enum::value4 == new_enum::value3) {
            std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
        }
        std::cout << std::endl;
    }
};