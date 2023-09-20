#include <iostream>

#include "factory_method.h"

using namespace std;

void LeiFeng::sweep() {
    std::cout << "sweep()" << std::endl;
}

void LeiFeng::wash() {
    std::cout << "wash()" << std::endl;
}

void LeiFeng::buy_rice() {
    std::cout << "buy_rice()" << std::endl;
}