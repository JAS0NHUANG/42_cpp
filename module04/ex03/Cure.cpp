#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure default constructor called\n";
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called\n";
}

Cure::Cure(Cure const &toCopy) {
	std::cout << "Cure copy constructor called\n";
	*this = toCopy;
}

Cure &Cure::operator=(Cure const& toAssign){
	std::cout << "Cure copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
}

// member functions
Cure* Cure::clone(void) const {
	Cure* newCure = new Cure();
	return (newCure);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'swounds *\n";
}
