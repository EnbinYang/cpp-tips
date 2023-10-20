#include <iostream>

#include "play_adapter.h"

void Forwards::attack() {
    std::cout << "Forwards " << _name << " attack" << std::endl;
}

void Forwards::defense() {
    std::cout << "Forwards " << _name << " defense" << std::endl;
}

void Center::attack() {
    std::cout << "Center " << _name << " attack" << std::endl;
}

void Center::defense() {
    std::cout << "Center " << _name << " defense" << std::endl;
}

void Guards::attack() {
    std::cout << "Guards " << _name << " attack" << std::endl;
}

void Guards::defense() {
    std::cout << "Guards " << _name << " defense" << std::endl;
}

void ForeignCenter::set_name(const std::string &name) {
    this->_name = name;
}

std::string ForeignCenter::get_name() {
    return this->_name;
}

void ForeignCenter::cn_attack() {
    std::cout << "CN Center " << _name << " attack" << std::endl;
}

void ForeignCenter::cn_defense() {
    std::cout << "CN Center " << _name << " defense" << std::endl;
}

Translator::Translator(const std::string& name) : Player(name) {
    _foreign_center.set_name(_name);
}

void Translator::attack() {
    _foreign_center.cn_attack();
}

void Translator::defense() {
    _foreign_center.cn_defense();
}