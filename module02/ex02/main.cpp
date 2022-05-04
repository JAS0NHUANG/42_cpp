#include <iostream>

#include "Fixed.hpp"

int main( void ) {

	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );


		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << "a is greater then b? " << (a > b) << std::endl;
		std::cout << "a is lesser then b? " << (a < b) << std::endl;
		std::cout << "a is equal to b? " << (a == b) << std::endl;

		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a - b = " << (a - b) << std::endl;
		std::cout << "a * b = " << (a * b) << std::endl;
		std::cout << "a / b = " << (a / b) << std::endl;
		std::cout << "c / b = " << (c / b) << std::endl;
	}
	std::cout << "\n\n~~~~~~~~ subject tests ~~~~~~~~~\n\n";
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed c( b );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		std::cout << "\n\n~~~~~~~~ extra tests ~~~~~~~~~\n\n";

		std::cout << Fixed::min( a, b ) << std::endl;
		std::cout << Fixed(5.05f) / Fixed(2) << std::endl;
		std::cout << c << std::endl;
		std::cout << --c << std::endl;
		std::cout << --c << std::endl;
	}

	return 0;
}
