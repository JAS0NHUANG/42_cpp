#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

template<typename T>
class Array {
	public:
		// canonical
		Array(void);
		~Array(void);
		Array(Array const & toCopy);
		Array &operator=(Array const & toAssign);
		Array(unsigned int n);

		// member functions
		T & operator[](unsigned int index);
		unsigned int size(void) const;

	private:
		T				*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif // ARRAY_HPP_
