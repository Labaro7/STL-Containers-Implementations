#pragma once
#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <memory>
#include <iostream>

template <typename T>
struct Node {
	T val;
	std::shared_ptr<Node<T>> next;
	std::shared_ptr<Node<T>> prev;

	Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List {
public:
	List();
	List(T val);
	~List();

	void addNodeToTheEnd(T val);
	void printNodes();
	void printNodesReverse();


private:
	std::shared_ptr<Node<T>> _head;
	std::shared_ptr<Node<T>> _tail;
};

template <typename T>
List<T>::List(): _head(nullptr), _tail(nullptr) {}

template <typename T>
List<T>::List(T val) {
	_head = std::make_shared<Node<T>>(val);
	_tail = _head;
}

template <typename T>
List<T>::~List() {}


template <typename T>
void List<T>::addNodeToTheEnd(T val) {
	if(!_head) {
		_head = std::make_shared<Node<T>>(val);
		_tail = _head;
	}
	else {
		_tail->next = std::make_shared<Node<T>>(val);
		_tail->next->prev = _tail;
		_tail = _tail->next;
	}
}

template <typename T>
void List<T>::printNodes() {
	std::shared_ptr<Node<T>> current = _head;

	while (current) {
		std::cout << "[" << current->val << "]";
		if (current->next != nullptr) std::cout << "->";
		current = current->next;
	}

	std::cout << std::endl;
}

template <typename T>
void List<T>::printNodesReverse() {
	if (_tail) {
		std::shared_ptr<Node<T>> current = _tail;

		while (current) {
			std::cout << "[" << current->val << "]";
			if (current->prev != nullptr) std::cout << "->";
			current = current->prev;
		}

		std::cout << std::endl;
	}
	else {
		std::cout << "List is empty." << std::endl;
	}
}

#endif