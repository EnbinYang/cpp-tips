#include <iostream>

#include "simple_factory.h"

using namespace std;

int main() {
    try {
        std::cout << "Enter two numbers separated by a space:" << std::endl;
        std::string number_first, number_second;
        std::cin >> number_first >> number_second;

        std::cout << "Input operator (+ or -)" << std::endl;
        char operator_str;
        std::cin >> operator_str;

        Operation* op;
        op = OperationFactory::create_operation(operator_str);
        op->set_number_first(stod(number_first));
        op->set_number_second(stod(number_second));

        double res = op->get_result();
        std::cout << "Result is " << res << std::endl;
    } catch (char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}