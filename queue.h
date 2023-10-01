#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node {
	T val;
	std::shared_ptr<Node<T>> next;
	std::shared_ptr<Node<T>> prev;

	Node() : val(0), next(nullptr), prev(nullptr){ }
	Node(T val) : val(val), next(nullptr), prev(nullptr){ }
	Node(T val, std::shared_ptr<Node<T>> next) : val(val), next(next), prev(nullptr){ }
};


template <typename T>
class Queue {
public:
	Queue(): _size(0), _back(nullptr), _front(nullptr) { }
	~Queue() { }

	bool empty() const;
	void push(T val);
	void pop();
	T front() const;
	T back() const;
	size_t size() const;

	friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
		std::shared_ptr<Node<T>> ptr = queue._back;

		os << "[";

		while (ptr != nullptr) {
			os << ptr->val;

			if (ptr != queue._front)
				os << ", ";
			ptr = ptr->next;
		}

		os << "]";

		return os;
	}

private:
	std::shared_ptr<Node<T>> _back;
	std::shared_ptr<Node<T>> _front;
	size_t _size;
};


template <typename T>
bool Queue<T>::empty() const {
	return _size == 0;
}

template <typename T>
void Queue<T>::push(T val) {
	if (_size == 0) {
		_back = std::make_shared<Node<T>>(val);
		_front = _back;
	}
	else {
		std::shared_ptr<Node<T>> ptr = _back;
		_back = std::make_shared<Node<T>>(val, ptr);
		ptr->prev = _back;
	}

	_size++;
}

template <typename T>
void Queue<T>::pop() {
	try {
		if (empty()) {
			throw std::runtime_error("Queue is empty, cannot pop value. Exiting with value -1");
		}

		if (_back == _front) {
			_back.reset();
			_front.reset();
		}
		else {
			std::shared_ptr<Node<T>> ptr = _front->prev;
			_front.reset();
			_front = ptr;
		}

		_size--;
	}
	catch (const std::runtime_error& e) {
		std::cout << std::endl;
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
}

template <typename T>
T Queue<T>::front() const {
	try {
		if (empty()) {
			throw std::runtime_error("Queue is empty, cannot get front value. Exiting with value -1");
			return 0;
		}

		return _front->val;
	}
	catch (const std::runtime_error& e) {
		std::cout << std::endl;
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
}

template <typename T>
T Queue<T>::back() const {
	try {
		if (empty()) {
			throw std::runtime_error("Queue is empty, cannot get back value. Exiting with value -1");
			return 0;
		}

		return _back->val;
	}
	catch (const std::runtime_error& e) {
		std::cout << std::endl;
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
}

template <typename T>
size_t Queue<T>::size() const{
	return _size;
}

#endif
