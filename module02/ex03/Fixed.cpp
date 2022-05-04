#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::frctnl_bits = 8;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	constructor & destructor                                                  */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Fixed::Fixed( void ) {
	this->value = 0;
};

Fixed::Fixed( const Fixed &toCopy ) {
	*this = toCopy;
};

Fixed::Fixed( const int number) {
	this->value = number << frctnl_bits;
}

Fixed::Fixed( const float number) {
	this->value = roundf(number * ( 1 << frctnl_bits));
}

Fixed::~Fixed( void ) {
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	Copy assignment operator overload                                         */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Fixed &Fixed::operator=( const Fixed &toAssign ) {
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
/*	increment / decrement operators: ++, --         			              */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// pre-increment
Fixed	Fixed::operator++( void ) {
	this->value += 1;
	return (*this);
}

// post-increment
Fixed	Fixed::operator++( int ) {
	Fixed original(*this);

	this->value += 1;
	return (original);
}

// pre-decrement
Fixed	Fixed::operator--( void ) {
	this->value -= 1;
	return (*this);
}

// post-decrement
Fixed	Fixed::operator--( int ) {
	Fixed original(*this);

	this->value -= 1;
	return (original);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	min / max														  */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Fixed	&Fixed::min(Fixed &first, Fixed &second) {
	return (first.getRawBits() <= second.getRawBits() ? first : second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second) {
	return (first.getRawBits() >= second.getRawBits() ? first : second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second) {
	return (first.getRawBits() <= second.getRawBits() ? first : second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second) {
	return (first.getRawBits() >= second.getRawBits() ? first : second);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*	insertion operator overload					                              */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
std::ostream &operator<<(std::ostream &out, const Fixed &number) {
	out << number.toFloat();
	return (out);
}
