#include <iostream>
#include <cmath>
#include <cstdlib>

template<typename T>
void	iter(T *array, int size, void (*f)(T & item)) {
	for (int i = 0; i < size; i++) {
		(*f)(array[i]);
	}
}

template<typename T>
void	add(T & item) {
	item++;
}

template<typename T>
void	print(T & item) {
	std::cout << item << "\n";
}

