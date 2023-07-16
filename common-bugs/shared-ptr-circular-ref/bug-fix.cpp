#include <iostream>
#include <memory>

using namespace std;

class B;

class A {
public:
    std::shared_ptr<B> ptr;  // point to class B
};

class B {
public:
    std::weak_ptr<A> weak_ptr;  // point to class A (change to weak_ptr)
};

int main() {
    std::shared_ptr<A> a_ptr = std::make_shared<A>();
    std::shared_ptr<B> b_ptr = std::make_shared<B>();

    a_ptr->ptr = b_ptr;
    b_ptr->weak_ptr = a_ptr;

    std::cout << "counter reference of A = " << a_ptr.use_count() << std::endl;  // 1
    std::cout << "counter reference of B = " << b_ptr.use_count() << std::endl;  // 2

    return 0;
}
