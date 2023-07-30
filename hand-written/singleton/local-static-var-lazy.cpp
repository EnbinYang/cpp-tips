#include <iostream>
#include <thread>
#include <mutex>

#include <unistd.h>

using namespace std;

class Singleton {
public:
    static Singleton& get_instance();
    void print();

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton& signal) = delete;
    const Singleton& operator=(const Singleton& signal) = delete;
};

Singleton& Singleton::get_instance() {
    static Singleton singal;  // static var
    return singal;
}

void Singleton::print() {
    std::cout << "addr: " << this << std::endl;
}

Singleton::Singleton() {
    std::cout << "Singleton()" << std::endl;
}

Singleton::~Singleton() {
    std::cout << "~Singleton()" << std::endl;
}

// operator func
void test() {
    Singleton::get_instance().print();
}

int main() {
    // create three threads
    thread t1(test);
    thread t2(test);
    thread t3(test);

    // threads joined
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
