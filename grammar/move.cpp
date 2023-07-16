#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void get_size(std::vector<int>&& vec) {
    std::cout << "numbers size = " << vec.size() << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    get_size(std::move(numbers));

    numbers.clear();

    return 0;
}
