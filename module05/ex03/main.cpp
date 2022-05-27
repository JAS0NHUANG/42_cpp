#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(){
	std::cout << "~~~~~~~ Basic tests ~~~~~~~\n";
	std::cout << "------- b1 f1-------\n";
	Bureaucrat b1("b1", 150);
	Bureaucrat b2("b2", 1);
	AForm* rrf;
	ShrubberyCreationForm theForm = ShrubberyCreationForm("Nice Target");
	RobotomyRequestForm roboForm = RobotomyRequestForm("Robo Target");
	PresidentialPardonForm ppForm = PresidentialPardonForm("Pardon Target");

	/* AForm is abstract class. Not instanciable.
	AForm	f1("f1", 150, 150);
	AForm	f2("f2", 149, 149);
	*/
	rrf = new RobotomyRequestForm("Robo T");
	std::cout << b1;
	b1.signForm(theForm);
	b1.executeForm(theForm);
	b2.signForm(*rrf);
	b2.executeForm(*rrf);

	try {
		b2.signForm(theForm);
		b2.executeForm(theForm);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		ppForm.execute(b2);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		roboForm.execute(b2);
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
