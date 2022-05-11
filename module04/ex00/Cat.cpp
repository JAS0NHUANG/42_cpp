#include <iostream>
#include <string>

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called\n";
	this->type = "Cat";
};

Cat::~Cat( void ) {
	std::cout << "Cat destructor called\n";
};

Cat::Cat( const Cat &toCopy ) : Animal() {
	std::cout << "Cat copy constructor called\n";
	*this = toCopy;
};

Cat	&Cat::operator=( const Cat &toAssign ) {
	std::cout << "Cat copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

Cat::Cat( std::string name ) : Animal() {
	std::cout << "Cat constructor with parameter called\n";
	this->type = name;
};

void	Cat::makeSound( void ) const {
	std::cout << this->type << " makes no barking sound but miaouuuuuuu~~\n";
};
