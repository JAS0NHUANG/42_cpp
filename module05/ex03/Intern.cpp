#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

Intern::Intern (void) {
	VERBOSE && std::cout << "Intern default constructor called\n";
}

Intern::~Intern (void) {
	VERBOSE && std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern &toCopy) {
	VERBOSE && std::cout << "Intern copy constructor called\n";
	*this = toCopy;
}

Intern &Intern::operator=(const Intern &toAssign) {
	VERBOSE && std::cout << "Intern copy assignment overload called\n";
	(void)toAssign;
	return (*this);
}

Form* Intern::makeSCF(std::string target) const {
	return (new ShrubberyCreationForm(target));
};
Form* Intern::makeRRF(std::string target) const{
	return (new RobotomyRequestForm(target));
}
Form* Intern::makePPF(std::string target) const{
	return (new PresidentialPardonForm(target));
}


Form*	Intern::makeForm(std::string formType, std::string target) const {
	Form*	(Intern::*ft_ptr[3])(std::string) const = {&Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF};
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (formTypes[i].compare(formType) == 0) {
			return (this->*ft_ptr[i])(target);
		}
	}
	return (NULL);
}

