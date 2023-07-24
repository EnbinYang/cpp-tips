#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mutex1;
std::mutex mutex2;

void thread1_func() {
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 1: acquire mutex1" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::unique_lock<std::mutex> lock2(mutex2);
    std::cout << "Thread 2: acquire mutex2" << std::endl;  // dead lock

    lock2.unlock();
    lock1.unlock();
}

void thread2_func() {
    std::unique_lock<std::mutex> lock2(mutex2);
    std::cout << "Thread 2: acquire mutex1" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 1: acquire mutex1" << std::endl;  

    lock1.unlock();
    lock2.unlock();
}

int main() {
    std::thread thread1(thread1_func);
    std::thread thread2(thread2_func);

    thread1.join();
    thread2.join();

    return 0;
}