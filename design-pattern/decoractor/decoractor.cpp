#include <iostream>

#include "decoractor.h"

using namespace std;

Person::Person(std::string name) {
    _name = name;
}

void Person::show() {
    std::cout << "Decoractor: " << _name << std::endl;
}

void Finery::decorate(Human* component) {
    _component = component;
}

void Finery::show() {
    _component->show();
}

void Tshirts::show() {
    std::cout << "Tshirts ";
    Finery::show();
}

void BigTrouser::show() {
    std::cout << "BigTrouser ";
    Finery::show();
}

void Sneakers::show() {
    std::cout << "Sneakers ";
    Finery::show();
}

void LeatherShoes::show() {
    std::cout << "LeatherShoes ";
    Finery::show();
}

void Tie::show() {
    std::cout << "Tie ";
    Finery::show();
}

void Suit::show() {
    std::cout << "Suit ";
    Finery::show();
}