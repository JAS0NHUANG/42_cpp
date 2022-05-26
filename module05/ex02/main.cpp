#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	std::cout << "~~~~~~~ Basic tests ~~~~~~~\n";
	std::cout << "------- b1 f1-------\n";
	Bureaucrat b1("b1", 150);
	Form	f1("f1", 150, 150);
	Form	f2("f2", 149, 149);
	std::cout << b1;
	std::cout << "\n";
	try {
		std::cout << "Try to downgrade b1:\n";	
		b1.downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	b1.signForm(f1);
	std::cout << f1;
	std::cout << "\n";

	b1.signForm(f2);
	std::cout << f2;
	std::cout << "\n";

	try {
		std::cout << "Try to upgrade b1:\n";	
		b1.upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	std::cout << b1;
	std::cout << "\n";

	b1.signForm(f1);
	std::cout << f1;

	b1.signForm(f2);
	std::cout << f2;

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
		Form f3("abcde", 0, 0);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Form f4("abcde", 5, 222);
	} catch (std::exception &e) {
		std::cout << e.what();
	}


	return (0);
}
