#include <iostream>

#include "Converter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "This converter takes one and only one argument.\n";
		std::cout << "Ex: ./Converter 42\n";
		return (1);
	}
	Converter thisConverter(av[1]);
	thisConverter.printResults();
}
