#include <iostream>
#include <future>
#include <thread>

using namespace std;

int get_sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // sleep two seconds

    return a + b;
}

int main() {
    // creat asynchronous task
    std::future<int> future_res = std::async(std::launch::async, get_sum, 2, 3);
    std::cout << "Doing some work..." << std::endl;

    int res = future_res.get();  // get asynchronous task result
    std::cout << "sum = " << res <<std::endl;

    return 0;
}
