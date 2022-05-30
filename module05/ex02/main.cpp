#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(){
	std::cout << "~~~~~~~ Basic tests ~~~~~~~\n";
	Bureaucrat b1("b1", 150);
	Bureaucrat b2("b2", 1);

	ShrubberyCreationForm scfForm = ShrubberyCreationForm("SCF_Target");
	RobotomyRequestForm roboForm = RobotomyRequestForm("RRF_Target");
	PresidentialPardonForm ppForm = PresidentialPardonForm("PPF_Target");

	/* Form is an abstract class, can't be instatiate.
	Form	f1("f1", 150, 150);
	Form	f2("f2", 149, 149);
	*/

	std::cout << b1;
	b1.signForm(scfForm);
	b1.executeForm(scfForm);
	std::cout << "\n";

	b2.signForm(scfForm);
	b2.executeForm(scfForm);
	std::cout << "\n";

	b2.signForm(roboForm);
	roboForm.execute(b2);
	std::cout << "\n";

	try {
		b2.signForm(ppForm);
		ppForm.execute(b2);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	try {
		std::cout << "Try to downgrade b1:\n";
		b1.downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	/*
	b1.signForm(f1);
	std::cout << f1;
	std::cout << "\n";

	b1.signForm(f2);
	std::cout << f2;
	std::cout << "\n";
	*/

	try {
		std::cout << "Try to upgrade b1:\n";
		b1.upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	std::cout << b1;
	std::cout << "\n";

	/*
	b1.signForm(f1);
	std::cout << f1;

	b1.signForm(f2);
	std::cout << f2;
	*/


	std::cout << "~~~~~~~ instancialize with bad grade value ~~~~~~~\n";

	try {
		Bureaucrat b3("abcde", 12345);
		std::cout << b1 << "\n";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	/*
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
	*/


	return (0);
}
