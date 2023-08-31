#include <iostream>

using namespace std;

class Basic {
public:
    Basic(size_t* data) : _data(new size_t(0)) {

    }

    Basic(const Basic& other) : _data(other._data) {

    }

    Basic& operator=(const Basic& other) {
        if (this != &other) {
            delete _data;
            _data = new size_t(*other._data);
        }

        return *this;
    }

    Basic(Basic&& other) {
        _data = other._data;
        other._data = nullptr;
    }

    Basic& operator=(Basic&& other) {
        if (this != &other) {
            delete _data;
            _data = other._data;
            other._data = nullptr;
        }

        return *this;
    }

    ~Basic() {
        if (_data) {
            delete _data;
            _data = nullptr;
        }
    }

private:
    size_t* _data;
};