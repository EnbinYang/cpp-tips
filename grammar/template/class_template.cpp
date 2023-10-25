#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob() : _data(std::make_shared<std::vector<T>>()) {}
    Blob(std::initializer_list<T> init_list) : _data(std::make_shared<std::vector<T>>(init_list)) {}

    size_type size() const {
        return _data->size();
    }

    bool empty() const {
        return _data->empty();
    }

    void push_back(const T& t) {
        _data->push_back(t);
    }

    void push_back(T&& t) {
        _data->push_back(std::move(t));
    }

    void pop_back() {
        check(0, "pop_back on empty Blob");
        _data->pop_back();
    }

    T& back() {
        check(0, "back on empty Blob");
        return _data->back();
    }

    T& operator[](size_type i) {
        check(0, "subscript out of range");
        return (*_data)[i];
    }

private:
    std::shared_ptr<std::vector<T>> _data;

    void check(size_type i, const std::string& msg) const {
        if (i >= _data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

int main() {
    Blob<int> b;
    Blob<int> b_init = {0, 1, 2, 3, 4};

    b_init.push_back(5);
    std::cout << b_init.size() << std::endl;
    std::cout << b_init[2] << std::endl;

    return 0;
}