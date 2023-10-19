#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyClass {
public:
    MyClass(int val) : _val(val) {}

    bool operator<(const MyClass& other) const {
        return _val < other._val;
    }

public:
    int _val;
};

int main() {
    std::vector<MyClass> vec;

    vec.push_back(MyClass(10));
    vec.push_back(MyClass(5));
    vec.push_back(MyClass(15));
    vec.push_back(MyClass(10));

    std::sort(vec.begin(), vec.end());

    for (const auto& obj : vec) {
        std::cout << obj._val << std::endl;
    }

    int target = 10;
    auto range = std::equal_range(vec.begin(), vec.end(), MyClass(target));
    if (range.first != range.second) {
        std::cout << "Found " << target << " in range [" << (*range.first)._val << ", " << (*(range.second - 1))._val << "]" << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}