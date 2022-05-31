#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Default SCF", 145, 137), _target("Default Target")
{
	VERBOSE && std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	VERBOSE && std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) :
	Form(toCopy.getName(), toCopy.getSignGrade(),
	toCopy.getExecGrade()), _target(toCopy.getTarget())
{
	VERBOSE && std::cout << "ShrubberyCreationForm copy constructor called\n";
	*this = toCopy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target ) :
	Form("SCF", 145, 137), _target(target)
{
	VERBOSE && std::cout << "ShrubberyCreationForm constructor with parameter called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toAssign) {
	VERBOSE && std::cout << "ShrubberyCreationForm copy assignment overload called\n";
	this->setIsSigned(toAssign.getIsSigned());
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

// member functions
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (!this->getIsSigned())
		throw Form::FormUnsignedException();
	std::fstream file;
	std::string	fileName = this->_target;
	file.open(fileName.append("_shrubbery").c_str(), std::fstream::out);
	file << \
		"         (root)\n" <<
		"         /    \\\n" <<
		"      (L)     (R)\n" <<
		"      / \\     / \\\n" <<
		"    (L) (R) (L) (R)\n" <<
		"\n" <<
		"(This is a geek tree!)\n";
	std::cout << executor.getName() << " executed " << this->getName() << "\n";
	std::cout << "Create \"" << fileName << "\" and write a tree inside the file.\n";
}
