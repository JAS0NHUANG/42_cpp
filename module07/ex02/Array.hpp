#include <iostream>

template<typename T>
class Array {
	public:
		// canonical
		Array(void) : _array(new T[0]), _size(0) {}
		~Array(void) {}
		Array(Array const & toCopy) { *this = toCopy; }
		Array &operator=(Array const & toAssign) {
			this->_array = toAssign._array;
			return (*this);
		}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		// member functions
		T & operator[](unsigned int index) { 
			if (index < 0 || index >= this->size())
				throw std::exception();
			return (this->_array[index]);
		}
		unsigned int size(void) const { return (this->_size); }

	private:
		T				*_array;
		unsigned int	_size;
};
