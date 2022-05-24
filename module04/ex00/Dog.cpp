#include <iostream>
#include <string>

#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "🐶 Dog default constructor called\n";
	this->type = "Dog";
};

Dog::~Dog( void ) {
	std::cout << "🐶 Dog destructor called\n";
};

Dog::Dog( const Dog &toCopy ) : Animal() {
	std::cout << "🐶 Dog copy constructor called\n";
	*this = toCopy;
};

Dog	&Dog::operator=( const Dog &toAssign ) {
	std::cout << "🐶 Dog copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

void	Dog::makeSound( void ) const {
	std::cout << "🐶 " << this->type << " makes a barking sound!\n";
};
