#ifndef VECTOR_HPP
#define	VECTOR_HPP

#include <memory>

constexpr size_t INITIAL_CAPACITY = 32;

template <typename T>
class Vector {
public:
	Vector() : _size(0), _capacity(INITIAL_CAPACITY), _data(new T[INITIAL_CAPACITY]) {}
	Vector(size_t capacity) : _size(0), _capacity(capacity), _data(new T[capacity]) {}
	~Vector(){}

	bool empty() const;
	T at(int i) const;
	void reallocate_and_push_back(T val);
	void push_back(T val);
	void pop_back();
	T front() const;
	T back() const;
	size_t size() const;

private:
	size_t _size;
	size_t _capacity;
	std::unique_ptr<T[]> _data;
};



template <typename T>
bool Vector<T>::empty() const {
	return _size == 0;
}

template <typename T>
T Vector<T>::at(int i) const {
	try {
		if (i >= _size) {
			throw std::runtime_error("Vector access out of bounds. Exiting with code -1");
		}
	}
	catch(std::runtime_error& e) {
		std::cerr << std::endl << e.what() << std::endl;
		exit(-1);
	}

	return _data[i];
}

template <typename T> // tendra que ser privado para que solo lo use push_back
void Vector<T>::reallocate_and_push_back(T val) {
	_capacity *= 2;

	//std::cout << std::endl << "REALOCATING..." << std::endl;

	std::unique_ptr<T[]> new_data = std::make_unique<T[]>(_capacity);
	std::copy(_data.get(), _data.get() + _size, new_data.get());

	_data = std::move(new_data);
	_data[_size] = val;

	_size++;

}

template <typename T>
void Vector<T>::push_back(T val) {
	try {
		if (_size == _capacity) {
			throw std::out_of_range("Max size reached");
		}

		_data[_size] = val;
		_size++;

	}
	catch (std::out_of_range) {
		reallocate_and_push_back(val);
	}

}

template <typename T>
void Vector<T>::pop_back() {
	try {
		if (_size <= 0) {
			throw std::out_of_range("Vector is empty.");
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << std::endl << e.what() << std::endl;
	}

	_data[_size - 1] = 0;
	_size--;
}

template <typename T>
T Vector<T>::front() const {
	try {
		if (_size <= 0) {
			throw std::out_of_range("Vector is empty.");
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << std::endl << e.what() << std::endl;
	}

	return _data[_size-1];
}

template <typename T>
T Vector<T>::back() const {
	try {
		if (_size <= 0) {
			throw std::out_of_range("Vector is empty.");
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << std::endl << e.what() << std::endl;
	}

	return _data[0];
}

template <typename T>
size_t Vector<T>::size() const {
	return _size;
}

#endif
