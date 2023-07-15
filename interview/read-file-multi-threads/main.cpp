#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

static int sum = 0;
std::mutex mtx;

void process_file(const std::string& filename) {
    int file_sum = 0;

    std::ifstream file(filename);
    if (file.is_open()) {
        int num = 0;
        while (file >> num) {
            file_sum += num;
        }
        file.close();
    } else {
        std::cout << "Failed to open file " << filename << std::endl;
    }

    std::lock_guard<std::mutex> lock(mtx);
    sum += file_sum;
}

int main() {
    std::vector<std::string> filelist = {"file1", "file2", "file3"};
    std::vector<std::thread> threads;

    for (const std::string& filename : filelist) {
        threads.emplace_back(process_file, filename);
    }

    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
