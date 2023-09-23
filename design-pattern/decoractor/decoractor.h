#ifndef DECORACTOR_H
#define DECORACTOR_H

#include <string>

class Human {
public:
    Human() {};
    Human(std::string name) {};
    virtual void show() = 0;

protected:
    std::string _name;
};

class Person : public Human {
public:
    explicit Person(std::string name);
    void show() override;
};

class Finery : public Human {
public:
    Finery() {};
    void decorate(Human* component);
    void show() override;

protected:
    Human* _component;
};

class Tshirts : public Finery {
public:
    void show() override;
};

class BigTrouser : public Finery {
public:
    void show() override;
};

class Sneakers : public Finery {
public:
    void show() override;
};

class LeatherShoes : public Finery {
public:
    void show() override;
};

class Tie : public Finery {
public:
    void show() override;
};

class Suit : public Finery {
public:
    void show() override;
};

#endif