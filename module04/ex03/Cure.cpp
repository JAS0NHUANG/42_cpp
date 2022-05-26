#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

Cure::Cure(void) : AMateria("cure") {
	VERBOSE && std::cout << "🩸 Cure default constructor called\n";
}

Cure::~Cure(void) {
	VERBOSE && std::cout << "🩸 Cure destructor called\n";
}

Cure::Cure(Cure const &toCopy) {
	VERBOSE && std::cout << "🩸 Cure copy constructor called\n";
	*this = toCopy;
}

Cure &Cure::operator=(Cure const& toAssign){
	VERBOSE && std::cout << "🩸 Cure copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
}

// member functions
Cure* Cure::clone(void) const {
	Cure* newCure = new Cure();
	return (newCure);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
