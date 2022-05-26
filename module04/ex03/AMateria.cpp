#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

AMateria::AMateria(void){
	VERBOSE && std::cout << "🪄  AMateria default constructor called\n";
};

AMateria::AMateria(std::string const& type) : type(type) {
	VERBOSE && std::cout << "🪄  AMateria constructor with type called\n";
};

AMateria::~AMateria(void){
	VERBOSE && std::cout << "🪄  AMateria destructor called\n";
};

AMateria::AMateria(const AMateria &toCopy){
	VERBOSE && std::cout << "🪄  AMateria copy constructor called\n";
	*this=toCopy;
};

AMateria &AMateria::operator=(const AMateria &toAssign){
	VERBOSE && std::cout << "🪄  AMateria copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

std::string const& AMateria::getType() const {
	return (this->type);
};

void	AMateria::use(ICharacter &){}
