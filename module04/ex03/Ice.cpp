#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

Ice::Ice(void) : AMateria("ice") {
	VERBOSE && std::cout << "🍦 Ice default constructor called\n";
}

Ice::~Ice(void) {
	VERBOSE && std::cout << "🍦 Ice destructor called\n";
}

Ice::Ice(Ice const &toCopy) : AMateria("ice") {
	VERBOSE && std::cout << "🍦 Ice copy constructor called\n";
	*this = toCopy;
}

Ice &Ice::operator=(Ice const&){
	VERBOSE && std::cout << "🍦 Ice copy assignment overload called\n";
	return (*this);
}


Ice* Ice::clone(void) const {
	Ice* newIce = new Ice();
	return (newIce);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
