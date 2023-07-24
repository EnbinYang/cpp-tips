#include <iostream>
#include <cmath>

using namespace std;

uint64_t clearBitsInRange(uint64_t num, int m, int n) {
    int bits = log10(num) + 1;
    uint64_t left_mask = pow(10, bits - m + 1);
    uint64_t right_mask = pow(10, bits - n);

    uint64_t left_num = num / left_mask;
    uint64_t right_num = num % right_mask;

    return left_mask * left_num + right_num;
}

int main() {
    uint64_t num = 123456789;
    int m = 3, n = 6;

    uint64_t res = clearBitsInRange(num, m, n);

    std::cout << "origin number: " << num << std::endl;
    std::cout << "final number: " << res << std::endl;

    return 0;
}