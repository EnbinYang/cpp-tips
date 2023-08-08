#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7};
    int x = 5;

    // delete all numbers less than 5 in 'nums'
    nums.erase(std::remove_if(nums.begin(), nums.end(), [x](int n) { return n < x; }), nums.end());

    for (auto num : nums) {
        std::cout << num << std::endl;
    }

    auto func1 = [](int i) { return i + 4; };
    std::cout << "func1: " << func1(6) << std::endl;

    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << std::endl;
}
