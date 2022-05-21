#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "🍦 Ice default constructor called\n";
}

Ice::~Ice(void) {
	std::cout << "🍦 Ice destructor called\n";
}

Ice::Ice(Ice const &toCopy) : AMateria("ice") {
	std::cout << "🍦 Ice copy constructor called\n";
	*this = toCopy;
}

Ice &Ice::operator=(Ice const&){
	std::cout << "🍦 Ice copy assignment overload called\n";
	return (*this);
}


Ice* Ice::clone(void) const {
	Ice* newIce = new Ice();
	return (newIce);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
