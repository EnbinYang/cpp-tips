#include <iostream>
#include <vector>

template <typename T>
int compare_func(const T& val1, const T& val2) {
    return val1 <= val2 ? (val1 == val2 ? 0 : -1) : 1;
}

int main() {
    std::cout << compare_func(2, 1) << std::endl;

    std::vector<int> vec1 = {1, 2, 3}, vec2 = {4, 5, 6};
    std::cout << compare_func(vec1, vec2) << std::endl;

    return 0;
}