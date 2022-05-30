#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(){
	std::cout << "~~~~~~~ Intern tests ~~~~~~~\n";
	Bureaucrat b1("b1", 80);
	Bureaucrat b2("b2", 25);
	std::cout << b1;
	std::cout << b2;
	std::cout << "\n";

	Form*	rrf;
	Intern	someRandomIntern;
	rrf = someRandomIntern.makeForm("robotomy request", "RRF_Target");

	b1.signForm(*rrf);
	b1.executeForm(*rrf);
	b2.signForm(*rrf);
	b2.executeForm(*rrf);

	delete rrf;
	std::cout << "\n";

	Form*	scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "SCF_Target");

	b1.signForm(*scf);
	b1.executeForm(*scf);
	b2.signForm(*scf);
	b2.executeForm(*scf);

	delete scf;
	std::cout << "\n";

	Form*	ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "PPF_Target");

	b1.signForm(*ppf);
	b1.executeForm(*ppf);
	b2.signForm(*ppf);
	b2.executeForm(*ppf);

	delete ppf;
	std::cout << "\n";


	return (0);
}
