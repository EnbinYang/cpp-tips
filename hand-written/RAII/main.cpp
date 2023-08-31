#include <iostream>
#include <memory>

using namespace std;

class Resource {
public:
    Resource() {
        std::cout << "Resource()" << std::endl;
    }

    ~Resource() {
        std::cout << "~Resource()" << std::endl;
    }

    void work_func() {
        std::cout << "work_func()" << std::endl;
    }
};

class ResourceManager {
public:
    ResourceManager() : _resource_ptr(std::make_unique<Resource>()) {  // C++14
        std::cout << "ResourceManager()" << std::endl;
    }

    void work_with_resource() {
        _resource_ptr->work_func();
    }

private:
    std::unique_ptr<Resource> _resource_ptr;
};

int main() {
    ResourceManager manager;
    manager.work_with_resource();

    return 0;
}