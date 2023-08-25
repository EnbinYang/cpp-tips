#include <vector>

using namespace std;

int main() {
	std::vector<int>* vec = new std::vector<int>;

	for (int i = 0; i < 1000; i++) {
		vec->push_back(i);
	}

	return 0;
}
