/**
 * @file ImplFunc.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Try to implement the given function
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class ImplFunc {
private:
    /// @brief To update each value into hash_code of each key
    template <typename Key, typename Value, typename F>
    void update(std::map<Key, Value>& m, F foo) {
        for (auto&& [key, value] : m) {
            value = foo(key);
        }
    }

    void mainFunction() {
        std::map<std::string, long long int> m {
            { "a", 1 },
            { "b", 2 },
            { "c", 3 }
        };
        update(m, [](const std::string& key) {
            return std::hash<std::string> {}(key);
        });
        for (auto&& [key, value] : m) {
            std::cout << key << ": " << value << std::endl;
        }
    }

public:
    static void example() {
        ImplFunc TestObj;
        TestObj.mainFunction();
        std::cout << std::endl;
    }
};