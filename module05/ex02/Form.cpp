#include <iostream>
#include "Form.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

Form::Form(void) :
	_name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {
	VERBOSE && std::cout << "Form default constructor called\n";
}

Form::~Form(void) {
	VERBOSE && std::cout << "Form destructor called\n";
}

Form::Form(const Form &toCopy) :
	_name(toCopy.getName()), _signGrade(toCopy.getSignGrade()), _execGrade(toCopy.getExecGrade()) {
	VERBOSE && std::cout << "Form copy constructor called\n";
	*this = toCopy;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade) {
	VERBOSE && std::cout << "Form default constructor called\n";
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (execGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &toAssign) {
	VERBOSE && std::cout << "Form copy assignment overload called\n";
	this->_isSigned = toAssign.getIsSigned();
	return (*this);
}

// accessor
std::string		Form::getName(void) const {
	return this->_name;
}

bool			Form::getIsSigned(void) const {
	return this->_isSigned;
}

unsigned int	Form::getSignGrade(void) const {
	return this->_signGrade;
}

unsigned int	Form::getExecGrade(void) const {
	return this->_execGrade;
}

void	Form::setIsSigned(bool isSigned) {
	this->_isSigned = isSigned;
}


// exception hendling
const char* Form::GradeTooLowException::what() const throw() {
		return ("the grade is too Low.\n");
}

const char* Form::GradeTooHighException::what() const throw() {
		return ("the grade is too High.\n");
}

const char* Form::FormUnsignedException::what() const throw() {
		return ("the form is not signed.\n");
}

// member functions
void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->setIsSigned(true);
}

std::ostream	&operator<<(std::ostream& out, const Form& f) {
	out << "Form name: " << f.getName() << \
		", is signed: " << f.getIsSigned() << \
		", sign grade: " << f.getSignGrade() << \
		", execute grade: " << f.getExecGrade() << "\n";
	return out;
}
