#include <iostream>
#include <stdint.h>

typedef struct	s_data {
	char			c;
	int				i;
	float			f;
	double			d;
	std::string		s;
} Data;

uintptr_t	serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int	main(void) {
	Data	data;
	Data	*dataPtr;
	uintptr_t	ptr;

	dataPtr = NULL;
	ptr = 0;

	data.c = 'C';
	data.i = 42;
	data.f = 42.42f;
	data.d = 42.4242;
	data.s = "I'm a data!";

	std::cout << "The data inside the original Data structure:" << "\n";

	std::cout << data.c << "\n";
	std::cout << data.i << "\n";
	std::cout << data.f << "\n";
	std::cout << data.d << "\n";
	std::cout << data.s << "\n";
	std::cout << "\n";

	ptr = serialize(&data);

	dataPtr = deserialize(ptr);

	std::cout << "The data inside the serialized and deserialized Data structure:" << "\n";
	std::cout << dataPtr->c << "\n";
	std::cout << dataPtr->i << "\n";
	std::cout << dataPtr->f << "\n";
	std::cout << dataPtr->d << "\n";
	std::cout << dataPtr->s << "\n";

}
