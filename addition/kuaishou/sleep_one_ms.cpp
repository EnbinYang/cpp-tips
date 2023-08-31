#include <chrono>
#include <thread>

using namespace std;

int main() {
    int count = 0;
    std::chrono::milliseconds duration(1);

    while (true) {
        count++;
        std::this_thread::sleep_for(duration);
    }

    return 0;
}