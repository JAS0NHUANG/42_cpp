#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::frctnl_bits = 8;

// constructors
Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->value = 0;
};

// constructor overload (int)
Fixed::Fixed(const int number) {
	std::cout << "int constructor called\n";
	this->value = number << frctnl_bits;
};

// constructor overload (float)
Fixed::Fixed(const float number) {
	std::cout << "float constructor called\n";
	this->value = roundf(number * (1 << frctnl_bits));
};

// destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
};

Fixed::Fixed(const Fixed &toCopy) {
	std::cout << "Copy constructor called\n";
	*this = toCopy;
};

Fixed &Fixed::operator=(const Fixed &toAssign) {
	std::cout << "Copy assignment operator called\n";
	this->value = toAssign.getRawBits();
	return (*this);
};

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->value);
};

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
};

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / ( 1 << frctnl_bits));
}

int	Fixed::toInt(void) const {
	return ((int)this->getRawBits() >> frctnl_bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &number){
	out << number.toFloat();
	return (out);
}
