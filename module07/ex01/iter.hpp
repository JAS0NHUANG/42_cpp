#include <iostream>

template<typename T>
void	iter(T *array, int size, void (*f)(T & item)) {
	for (int i = 0; i < size; i++) {
		(*f)(array[i]);
	}
}

template<typename T>
void	add(T & item) {
	try {
		item++;
	} catch (std::exception & e) {
		std::cout << "Can't add on this type: " << e.what() << "/n";
	}
}

template<typename T>
void	print(T & item) {
	std::cout << item << "\n";
}

