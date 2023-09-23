#include <iostream>

#include "decoractor.h"

using namespace std;

int main() {
    try {
        Person* p = new Person("enbin");

        std::cout << "First Instance:" << std::endl;
        Sneakers* s = new Sneakers();
        BigTrouser* b = new BigTrouser();
        Tshirts* t = new Tshirts();
        s->decorate(p);
        b->decorate(s);
        t->decorate(b);
        t->show();
    } catch (char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}