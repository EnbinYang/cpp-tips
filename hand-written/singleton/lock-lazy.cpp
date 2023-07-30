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
    static Singleton *m_Instance;
    static std::mutex m_Mutex;

private:
    class AutoRelease {
    public:
        AutoRelease() {
            std::cout << "AutoRelease()" << std::endl;
        }
        ~AutoRelease() {
            std::unique_lock<std::mutex> lock(m_Mutex);
            if (m_Instance) {
                delete m_Instance;
                m_Instance = nullptr;
            }
            std::cout << "~AutoRelease()" << std::endl;
        }
    };

private:
    static AutoRelease m_At;
};

Singleton *Singleton::m_Instance = nullptr;
std::mutex Singleton::m_Mutex;
Singleton::AutoRelease Singleton::m_At;

Singleton* Singleton::get_instance() {
    if (m_Instance == nullptr) {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_Instance == nullptr) {
            m_Instance = new Singleton;
        }
    }

    return m_Instance;
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
