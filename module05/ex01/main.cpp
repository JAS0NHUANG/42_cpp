#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	Form	f1("f1", 150, 150);
	Form	f2("f2", 149, 149);
	std::cout << f1;
	std::cout << f2;
	std::cout << "\n";

	Bureaucrat b1("b1", 150);
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
	std::cout << "\n";
	b1.signForm(f2);
	std::cout << f2;
	std::cout << "\n";

	return (0);
}
