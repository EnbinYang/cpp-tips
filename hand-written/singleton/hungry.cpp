#include <iostream>
#include <thread>
#include <mutex>

#include <unistd.h>

using namespace std;

class Singleton {
public:
    static Singleton* get_instance();
    void print();

private:
    friend class AutoRelease;
    Singleton();
    ~Singleton();
    Singleton(const Singleton& signal) = delete;
    const Singleton& operator=(const Singleton& signal) = delete;

private:
    static Singleton *g_Instance;

private:
    class AutoRelease {
        public:
            AutoRelease() {
                std::cout << "AutoRelease()" << std::endl;
            }
            ~AutoRelease() {
                if (g_Instance) {
                    delete g_Instance;
                    g_Instance = nullptr;
                }
                std::cout << "~AutoRelease()" << std::endl;
            }
    };

private:
    static AutoRelease m_At;
};

/* create an instance when code runs */
Singleton *Singleton::g_Instance = new Singleton;
Singleton::AutoRelease Singleton::m_At;

Singleton* Singleton::get_instance() {
    return g_Instance;
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
    Singleton::get_instance()->print();
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
