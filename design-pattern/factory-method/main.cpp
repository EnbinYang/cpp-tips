#include <iostream>

#include "factory_method.h"

using namespace std;

int main() {
    try {
        ILeiFeng* factory = new VolunteerLeiFeng();
        LeiFeng* volunteer = factory->create_leifeng();
        volunteer->sweep();
        volunteer->wash();
        volunteer->buy_rice();
    } catch (char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}