#include <iostream>
#include <cmath>

#include "Fixed.hpp"

// assign a value to Fixed::frctnl_bits
const int Fixed::frctnl_bits = 8;

// constructors
Fixed::Fixed( void ) {
	std::cout << "Default constructor called\n";
	this->value = 0;
};

Fixed::Fixed( const Fixed &toCopy ) {
	std::cout << "Copy constructor called\n";
	*this = toCopy;
};

Fixed::Fixed( const int number) {
	std::cout << "Int constructor called\n";
	this->value = number << frctnl_bits;
}

Fixed::Fixed( const float number) {
	std::cout << "Float constructor called\n";
	this->value = roundf(number * ( 1 << frctnl_bits));
}

// destructor
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

// getter / setter
int	Fixed::getRawBits( void ) const {
	return (this->value);
};

void	Fixed::setRawBits( int const raw ) {
	this->value = raw;
};

// member functions
float	Fixed::toFloat( void ) const {
	return ((float)this->getRawBits() / (1 << frctnl_bits));
}

int	Fixed::toInt( void ) const {
	return (this->getRawBits() / (1 << frctnl_bits));
}

// insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &number) {
	out << number.toFloat();
	// need to return the ostream
	return (out);
}
