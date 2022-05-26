#include <iostream>
#include "Bureaucrat.hpp"

int	main(){
	std::cout << "~~~~~~~ Basic tests ~~~~~~~\n";
	std::cout << "------- b1 -------\n";
	Bureaucrat b1("b1", 150);
	std::cout << b1;
	std::cout << "\n";
	try {
		std::cout << "Try to downgrade b1:\n";	
		b1.downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		std::cout << "Try to upgrade b1:\n";	
		b1.upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << b1;
	std::cout << "\n";

	std::cout << "------- b2 -------\n";
	Bureaucrat b2("b2", 1);
	std::cout << b2 << "\n";
	try {
		std::cout << "Try to upgrade b2:\n";	
		b2.upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		std::cout << "Try to downgrade b2:\n";	
		b2.downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << b2 << "\n";
	std::cout << "\n";

	std::cout << "~~~~~~~ instancialize with bad grade value ~~~~~~~\n";

	try {
		Bureaucrat b3("abcde", 12345);
		std::cout << b1 << "\n";
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Bureaucrat b4("abcde", 0);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Bureaucrat b5("abcde", -1);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	return (0);
}
