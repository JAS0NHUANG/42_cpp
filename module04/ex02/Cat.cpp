#include <iostream>
#include <string>

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : AAnimal() {
	std::cout << "😺 Cat default constructor called\n";
	this->type = "Cat";
	this->name = "";
	this->catBrain = new Brain();
};

Cat::~Cat( void ) {
	std::cout << "😺 Cat destructor called\n";
	delete this->catBrain;
};

Cat::Cat( const Cat &toCopy ) : AAnimal() {
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

Cat::Cat( std::string name ) : AAnimal() {
	std::cout << "😺 Cat constructor with parameter called\n";
	this->name = name;
	this->type = name.append(" Cat");
	this->catBrain = new Brain();
};

const std::string	Cat::getType( void ) const {
	return (this->type);
}

void	Cat::makeSound( void ) const {
	std::cout << "😺 " << this->type << \
		" makes no barking sound but miaouuuuuuu~~\n";
};

void	Cat::addIdea( std::string idea ) {
	std::cout << "add \"" << idea << "\" into cat's brain\n";
	this->catBrain->addIdea( idea );
}

void	Cat::printIdeas( void ) const {
	this->catBrain->printIdeas();
}
