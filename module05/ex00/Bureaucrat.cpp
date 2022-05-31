#include "Bureaucrat.hpp"
#include <iostream>

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

Bureaucrat::Bureaucrat(void) :
	_name("Default Bureaucrat"), _grade(150)
{
	VERBOSE && std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::~Bureaucrat(void) {
	VERBOSE && std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
	_name(name), _grade(grade)
{
	VERBOSE && std::cout << "Bureaucrat constructor with parameters called\n";
	if (grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) {
	VERBOSE && std::cout << "Bureaucrat copy constructor called\n";
	*this = toCopy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& toAssign) {
	VERBOSE && std::cout << "Bureaucrat copy assignment operator overload called\n";
	this->_grade = toAssign._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// exception handling
const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return ("Error: The grade is too High(<1).\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return ("Error: The grade is too low(>150).\n");
}

// member functions
void	Bureaucrat::upgrade(void) { // minus
	if (this->_grade <= 1)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << " has been upgraded to " << this->_grade << "\n";
}

void	Bureaucrat::downgrade(void) {// plus
	if (this->_grade >= 150)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << this->_name << " has been downgraded to " << this->_grade << "\n";

}

// operator overload
std::ostream	&operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (out);
}
