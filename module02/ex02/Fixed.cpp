#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::frctnl_bits = 8;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	constructor & destructor                                                  */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
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

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	Copy assignment operator overload                                         */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Fixed &Fixed::operator=( const Fixed &toAssign ) {
	std::cout << "Copy assignment operator called\n";
	this->value = toAssign.getRawBits();
	return (*this);
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	getter / setter							                                  */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int	Fixed::getRawBits( void ) const {
	return (this->value);
};

void	Fixed::setRawBits( int const raw ) {
	this->value = raw;
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	member functions						                                  */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float	Fixed::toFloat( void ) const {
	return ((float)this->getRawBits() / (1 << Fixed::frctnl_bits));
}

int	Fixed::toInt( void ) const {
	return (this->getRawBits() / (1 << Fixed::frctnl_bits));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	comparison operators: >, <, >=, <=, ==, != 			                      */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool	Fixed::operator>( const Fixed &right ) const {
	return (this->getRawBits() > right.getRawBits());
}

bool	Fixed::operator<( const Fixed &right ) const {
	return (this->getRawBits() < right.getRawBits());
}

bool	Fixed::operator>=( const Fixed &right ) const {
	return (this->getRawBits() >= right.getRawBits());
}

bool	Fixed::operator<=( const Fixed &right ) const {
	return (this->getRawBits() <= right.getRawBits());
}

bool	Fixed::operator==( const Fixed &right ) const {
	return (this->getRawBits() == right.getRawBits());
}

bool	Fixed::operator!=( const Fixed &right ) const {
	return (this->getRawBits() != right.getRawBits());
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	arithmetic operators: +, -, *, /                			              */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Fixed	Fixed::operator+( const Fixed &right) const {
	return (Fixed((this->getRawBits() + right.getRawBits()) >> Fixed::frctnl_bits));
}

Fixed	Fixed::operator-( const Fixed &right) const {
	return (Fixed((this->getRawBits() - right.getRawBits()) >> Fixed::frctnl_bits));
}

Fixed	Fixed::operator*( const Fixed &right) const {
	return (Fixed(this->toFloat() * right.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &right) const {
	return (Fixed(this->toFloat() / right.toFloat()));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	insertion operator overload					                              */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
std::ostream &operator<<(std::ostream &out, const Fixed &number) {
	out << number.toFloat();
	// need to return the ostream
	return (out);
}
