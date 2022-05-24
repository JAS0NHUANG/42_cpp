#include <iostream>
#include <string>

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor called\n";
	this->type = "WrongCat";
};

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called\n";
};

WrongCat::WrongCat( const WrongCat &toCopy ) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called\n";
	*this = toCopy;
};

WrongCat	&WrongCat::operator=( const WrongCat &toAssign ) {
	std::cout << "WrongCat copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

void	WrongCat::makeSound( void ) const {
	std::cout << this->type << " makes no barking sound but miaouuuuuuu~~\n";
};
