#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(void){
	std::cout << "AMateria default constructor called\n";
};

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "AMateria constructor with type called\n";
};
AMateria::~AMateria(void){
	std::cout << "AMateria destructor called\n";
};

AMateria::AMateria(AMateria &toCopy){
	std::cout << "AMateria copy constructor called\n";
};
AMateria &AMateria::operator=(AMateria &toAssign){
	std::cout << "AMateria copy assignment overload called\n";
};

std::string const& AMateria::getType() const {
	return (this->type);
}; 
