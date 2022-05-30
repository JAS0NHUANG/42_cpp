#include <iostream>
#include <fstream>
#include "PresidentialPardonForm.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Default SCF", 25, 5),
	_target("Default Target") {
	VERBOSE && std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	VERBOSE && std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) :
	Form(toCopy.getName(), toCopy.getSignGrade(), toCopy.getExecGrade()), _target(toCopy.getTarget()) {
	VERBOSE && std::cout << "PresidentialPardonForm copy constructor called\n";
	*this = toCopy;
}

PresidentialPardonForm::PresidentialPardonForm(
	std::string target
) :
	Form("SCF", 25, 5),
	_target(target) {
	VERBOSE && std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &toAssign) {
	VERBOSE && std::cout << "PresidentialPardonForm copy assignment overload called\n";
	this->setIsSigned(toAssign.getIsSigned());
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

// member functions
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (!this->getIsSigned())
		throw Form::FormUnsignedException();
	std::cout << this->getTarget() << " is pardoned by Zaphod Beeblebrox.\n";
}
