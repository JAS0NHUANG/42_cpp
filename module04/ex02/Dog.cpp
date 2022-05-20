#include <iostream>
#include <string>

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "🐶 Dog default constructor called\n";
	this->type = "Dog";
	this->name = "";
	this->dogBrain = new Brain();
};

Dog::~Dog( void ) {
	std::cout << "🐶 Dog destructor called\n";
	delete this->dogBrain;
};

Dog::Dog( const Dog &toCopy ) : Animal() {
	std::cout << "🐶 Dog copy constructor called\n";
	this->dogBrain = new Brain();
	*this = toCopy;
};

Dog	&Dog::operator=( const Dog &toAssign ) {
	std::cout << "🐶 Dog copy assignment overload called\n";
	this->type = toAssign.type;
	this->name = toAssign.name;
	this->dogBrain = new Brain();
	return (*this);
};

Dog::Dog( std::string name ) : Animal() {
	std::cout << "🐶 Dog constructor with parameter called\n";
	this->name = name;
	this->type = name.append(" Dog");
	this->dogBrain = new Brain();
};

void	Dog::makeSound( void ) const {
	std::cout << "🐶 " << this->type << " makes a barking sound!\n";
};
