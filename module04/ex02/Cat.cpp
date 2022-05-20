#include <iostream>
#include <string>

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "😺 Cat default constructor called\n";
	this->type = "Cat";
	this->name = "";
	this->catBrain = new Brain();
};

Cat::~Cat( void ) {
	std::cout << "😺 Cat destructor called\n";
	delete this->catBrain;
};

Cat::Cat( const Cat &toCopy ) : Animal() {
	std::cout << "😺 Cat copy constructor called\n";
	this->type = toCopy.type;
	this->name = toCopy.name;
	this->catBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->catBrain->ideas[i] = toCopy.catBrain->ideas[i];
	}
};

Cat	&Cat::operator=( const Cat &toAssign ) {
	std::cout << "😺 Cat copy assignment overload called\n";
	this->type = toAssign.type;
	this->name = toAssign.name;
	this->catBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->catBrain->ideas[i] = toAssign.catBrain->ideas[i];
	}
	return (*this);
};

Cat::Cat( std::string name ) : Animal() {
	std::cout << "😺 Cat constructor with parameter called\n";
	this->name = name;
	this->type = name.append(" Cat");
	this->catBrain = new Brain();
};

void	Cat::makeSound( void ) const {
	std::cout << "😺 " << this->type << \
		" makes no barking sound but miaouuuuuuu~~\n";
};
