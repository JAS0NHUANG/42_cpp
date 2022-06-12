#include "Array.hpp"

// default constructor
template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {}

// default destructor
template <typename T>
Array<T>::~Array(void) {
	if (this->_array)
		delete [] this->_array;
}

// constructor with params
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	T * tmp = new T();
	for (unsigned int i = 0; i < n; i++) {
		this->_array[i] = *tmp;
	}
	delete tmp;
}

// copy constructor
template <typename T>
Array<T>::Array(Array const & toCopy) {
	std::cout << "copy assignment overload\n";
	this->_array = new T[toCopy.size()];
	this->_size = toCopy.size();
	for (unsigned int i = 0; i < toCopy.size(); i++) {
		this->_array[i] = toCopy._array[i];
	}
}

// copy assignment overload
template <typename T>
Array<T> &Array<T>::operator=(Array const & toAssign) {
	std::cout << "copy assignment overload\n";
	if (this->_array) {
		delete [] this->_array;
	}
	this->_array = new T[toAssign.size()];
	this->_size = toAssign.size();
	for (unsigned int i = 0; i < toAssign.size(); i++) {
		this->_array[i] = toAssign._array[i];
	}
	return (*this);
}

// [] operator overload
template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->size())
		throw std::exception();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const { return (this->_size); }
