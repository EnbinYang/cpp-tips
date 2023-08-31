#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

void worker_func(std::promise<int>& promise) {
    int res = 10;
    std::this_thread::sleep_for(std::chrono::seconds(5));  // work operation
    promise.set_value(res);
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();  // bind

    std::thread thread_worker(worker_func, std::ref(promise));  // get future by promise

    int res = future.get();
    std::cout << "future result = " << res << std::endl;

    thread_worker.join();

    return 0;
}