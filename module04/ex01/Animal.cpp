# include <iostream>

# include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << "👾 Animal default constructor called\n";
	this->type = "Animal";
};

Animal::~Animal( void ) {
	std::cout << "👾 Animal destructor called\n";
};

Animal::Animal( const Animal &toCopy ) {
	std::cout << "👾 Animal copy constructor called\n";
	*this = toCopy;
};

Animal	&Animal::operator=( const Animal &toAssign ) {
	std::cout << "👾 Animal copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

// getter
const std::string	Animal::getType( void ) const {
	return (this->type);
};

// member function
void	Animal::makeSound( void ) const {
	std::cout << "👾 Animal sound~~~\n";
};

void	Animal::addIdea(std::string idea) {
	(void)idea;
	return ;
}

void	Animal::printIdeas(void) const {
	return ;
}
