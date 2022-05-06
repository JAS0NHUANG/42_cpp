#include <iostream>

#include "Fixed.hpp"

// assign a value to Fixed::frctnl_bits
const int Fixed::frctnl_bits = 8;

// default constructor
Fixed::Fixed( void ) {
	std::cout << "Default constructor called\n";
	this->value = 0;
};

// copy constructor
Fixed::Fixed( const Fixed &toCopy ) {
	std::cout << "Copy constructor called\n";
	*this = toCopy;
};

// default destructor
Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
};

// Copy assignment operator overload
Fixed &Fixed::operator=( const Fixed &toAssign ) {
	std::cout << "Copy assignment operator called\n";
	// get the raw bits value by calling the getRawBits member function.
	this->value = toAssign.getRawBits();
	// return the object pointed by this.
	return (*this);
};

// getter
int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (this->value);
};

// setter
void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	this->value = raw;
};
