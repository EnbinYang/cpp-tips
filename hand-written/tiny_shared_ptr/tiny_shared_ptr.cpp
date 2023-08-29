#include <iostream>

#include "tiny_shared_ptr.h"

using namespace std;

class Test {
public:
    Test() {
        std::cout << "Test()" << std::endl;
    }

    ~Test() {
        std::cout << "~Test()" << std::endl;
    }

    void operation() {
        std::cout << "operation()" << std::endl;
    }
};

int main() {
    tiny_shared_ptr<Test> ptr(new Test);
    tiny_shared_ptr<Test> ptr_copy = ptr;

    std::cout << "ptr count = " << ptr.use_count() << std::endl;
    std::cout << "ptr_copy count = " << ptr_copy.use_count() << std::endl;
    
    ptr->operation();

    tiny_shared_ptr<Test> ptr_empty;
    std::cout << "ptr_empty count = " << ptr_empty.use_count() << std::endl;

    {
        tiny_shared_ptr<Test> ptr_local(new Test);
        std::cout << "ptr_local count = " << ptr_local.use_count() << std::endl;
    }

    return 0;
}
