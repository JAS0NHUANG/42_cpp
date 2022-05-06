#ifndef _POINT_HPP_
# define _POINT_HPP_

# include "Fixed.hpp"
# include <iostream>

class Point {

	public:
		Point( void );
		Point( Point const &toCopy);
		Point( const float x, const float y);
		Point	&operator=( Point const &toAssign);
		~Point( void );

		const Fixed	&getX( void ) const;
		const Fixed	&getY( void ) const;
		void	setX( float x);
		void	setY( float y);

	private:
		const Fixed x;
		const Fixed y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
