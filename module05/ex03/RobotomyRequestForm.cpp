#include <iostream>
#include <fstream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Default SCF", 72, 45),
	_target("Default Target") {
	VERBOSE && std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	VERBOSE && std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) :
	Form(toCopy.getName(), toCopy.getSignGrade(), toCopy.getExecGrade()), _target(toCopy.getTarget()) {
	VERBOSE && std::cout << "RobotomyRequestForm copy constructor called\n";
	*this = toCopy;
}

RobotomyRequestForm::RobotomyRequestForm(
	std::string target
) :
	Form("RRF", 72, 45),
	_target(target) {
	VERBOSE && std::cout << "RobotomyRequestForm constructor with parameter called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &toAssign) {
	VERBOSE && std::cout << "RobotomyRequestForm copy assignment overload called\n";
	this->setIsSigned(toAssign.getIsSigned());
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

// member functions
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (!this->getIsSigned())
		throw Form::FormUnsignedException();
	std::cout << "sszzsszzzsssSSSzZZZZSsszzsSSSSzZZZZZZ~~~~\n";
	srand(time(0));
	if (rand() % 2 == 0) {
		std::cout << this->getTarget() << " is robotomized!!\n";
	}
}
