#include "Point.hpp"

Point::Point( void ) : x(Fixed(0)), y(Fixed(0)) {};

Point::Point( const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {};

Point	&Point::operator=( Point const &toAssign) {
	*const_cast<Fixed*>(&this->x) = toAssign.x;
	*const_cast<Fixed*>(&this->y) = toAssign.y;
	return (*this);
};

Point::Point( Point const &toCopy) {
	*this = toCopy;
};

Point::~Point( void ) {};

const Fixed	&Point::getX( void ) const {
	return (this->x);
};

const Fixed	&Point::getY( void ) const {
	return (this->y);
};

void	Point::setX( float x) {
	*const_cast<Fixed*>(&this->x) = Fixed(x);
};

void	Point::setY( float y) {
	*const_cast<Fixed*>(&this->y) = Fixed(y);
}
