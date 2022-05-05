#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->value = 0;
};

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
