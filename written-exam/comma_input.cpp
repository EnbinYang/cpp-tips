#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> nums;

    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, ',')) {
        nums.push_back(std::stoi(token));
    }

    for (auto num : nums) {
        std::cout << num << std::endl;
    }

    return 0;
}