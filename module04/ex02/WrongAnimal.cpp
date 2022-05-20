# include <iostream>

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal default constructor called\n";
};

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called\n";
};

WrongAnimal::WrongAnimal( const WrongAnimal &toCopy ) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = toCopy;
};

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &toAssign ) {
	std::cout << "WrongAnimal copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

// getter
const std::string	WrongAnimal::getType( void ) const {
	return (this->type);
};

// member function
void	WrongAnimal::makeSound( void ) const {
	std::cout << "(WrongAnimal sound~~~)\n";
};
