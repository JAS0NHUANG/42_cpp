#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void){
	std::cout << "🪄  AMateria default constructor called\n";
};

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "🪄  AMateria constructor with type called\n";
};

AMateria::~AMateria(void){
	std::cout << "🪄  AMateria destructor called\n";
};

AMateria::AMateria(const AMateria &toCopy){
	std::cout << "🪄  AMateria copy constructor called\n";
	*this=toCopy;
};

AMateria &AMateria::operator=(const AMateria &toAssign){
	std::cout << "🪄  AMateria copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

std::string const& AMateria::getType() const {
	return (this->type);
};

void	AMateria::use(ICharacter &){}
