#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(){
	/* Form is an abstract class, can't be instatiate.
	Form	f1("f1", 150, 150);
	Form	f2("f2", 149, 149);
	*/

	Bureaucrat b1("b1", 150);
	std::cout << b1;
	Bureaucrat b2("b2", 1);
	std::cout << b2;
	std::cout << "\n";

	ShrubberyCreationForm scfForm = ShrubberyCreationForm("SCF_Target");
	std::cout << scfForm;
	RobotomyRequestForm roboForm = RobotomyRequestForm("RRF_Target");
	std::cout << roboForm;
	PresidentialPardonForm ppForm = PresidentialPardonForm("PPF_Target");
	std::cout << ppForm;
	std::cout << "\n";

	b1.signForm(scfForm);
	b1.executeForm(scfForm);
	std::cout << "\n";

	b2.signForm(scfForm);
	b2.executeForm(scfForm);
	std::cout << "\n";

	b2.signForm(roboForm);
	b2.executeForm(roboForm);
	std::cout << "\n";

	b2.signForm(ppForm);
	b2.executeForm(ppForm);
	std::cout << "\n";

	b1.signForm(ppForm);
	b1.executeForm(ppForm);
	std::cout << "\n";

	return (0);
}
