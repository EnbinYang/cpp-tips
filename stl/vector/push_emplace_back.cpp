#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
    Test(const std::string& str) : m_data(str) {
        std::cout << "Test(): " << m_data << std::endl;
    }

    Test(const Test& other) : m_data(other.m_data) {
        std::cout << "Copy Test(): " << m_data << std::endl;
    } 

private:
    std::string m_data;
};

int main() {
    std::vector<Test> vec;
    vec.reserve(5);

    Test t1("t1");
    vec.push_back(t1);

    vec.emplace_back("t2");

    return 0;
}
