template <typename T>
class tiny_shared_ptr {
public:
	tiny_shared_ptr(T* ptr = nullptr) : _ptr(ptr), _count(new size_t(1)) {
		if (_ptr == nullptr) {
			*_count = 0;
		}
	}

	tiny_shared_ptr(const tiny_shared_ptr<T>& other) : _ptr(other._ptr), _count(other._count) {
		if (_ptr) {
			(*_count)++;
		}
	}

	tiny_shared_ptr<T>& operator=(const tiny_shared_ptr<T>& other) {
		if (this != &other) {
            release_source();
			_ptr = other._ptr;
			_count = other._count;
			if (_ptr) {
                (*_count)++;
            }
		}

		return *this;
	}

	T* operator->() const {
		return _ptr;
	}

    int use_count() const {
		return (_count ? *_count : 0);
	}

	~tiny_shared_ptr() {
        release_source();
	}

private:
    void release_source() {
        if (_count) {
            (*_count)--;
            if (*_count == 0) {
                delete _ptr;
                delete _count;
            }
        }
    }

	T* _ptr;
	size_t* _count;
};
