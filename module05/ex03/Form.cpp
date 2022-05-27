#include <iostream>
#include "Form.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

AForm::AForm(void) :
	_name("Default AForm"), _isSigned(false), _signGrade(150), _execGrade(150) {
	VERBOSE && std::cout << "AForm default constructor called\n";
}

AForm::~AForm(void) {
	VERBOSE && std::cout << "AForm destructor called\n";
}

AForm::AForm(const AForm &toCopy) :
	_name(toCopy.getName()), _signGrade(toCopy.getSignGrade()), _execGrade(toCopy.getExecGrade()) {
	VERBOSE && std::cout << "AForm copy constructor called\n";
	*this = toCopy;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade) {
	VERBOSE && std::cout << "AForm default constructor called\n";
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (execGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &toAssign) {
	VERBOSE && std::cout << "AForm copy assignment overload called\n";
	this->_isSigned = toAssign.getIsSigned();
	return (*this);
}

// accessor
std::string		AForm::getName(void) const {
	return this->_name;
}

bool			AForm::getIsSigned(void) const {
	return this->_isSigned;
}

unsigned int	AForm::getSignGrade(void) const {
	return this->_signGrade;
}

unsigned int	AForm::getExecGrade(void) const {
	return this->_execGrade;
}

void	AForm::setIsSigned(bool isSigned) {
	this->_isSigned = isSigned;
}


// exception hendling
const char* AForm::GradeTooLowException::what() const throw() {
		return ("the grade is too Low.\n");
}

const char* AForm::GradeTooHighException::what() const throw() {
		return ("the grade is too High.\n");
}

const char* AForm::FormUnsignedException::what() const throw() {
		return ("the form is not signed.\n");
}

// member functions
void	AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->setIsSigned(true);
}

std::ostream	&operator<<(std::ostream& out, const AForm& f) {
	out << "AForm name: " << f.getName() << \
		", is signed: " << f.getIsSigned() << \
		", sign grade: " << f.getSignGrade() << \
		", execute grade: " << f.getExecGrade() << "\n";
	return out;
}
