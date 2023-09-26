#include <iostream>

using namespace std;

class Base {
public:
    Base() {};
    ~Base() {};
    virtual void func() {};
    void foo() {};
};

class MyClass : protected Base {
public:
    MyClass() {
        _p = new int;
    }

    ~MyClass() {
        if (_p != nullptr) {
            delete _p;
        }
    }

    void func() {};

private:
    int* _p;
    static int _global;
};

MyClass::_global = 10;  // bug-1: modify member variable outside the class

int main() {
    MyClass a, b;
    a.foo();  // bug-2: foo() is protected

    b = a;  // bug-3: shallow copy
    Base* base = &a;  // bug-4: cannot assign MyClass object to pointer to Base
    base->func();

    return 0;
}