#include <iostream>
#include <iomanip>

#include "Fixed.hpp"

int main( void ) {

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

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min in a and b: " << Fixed::min( a, b ) << std::endl;
		std::cout << "max in a and b: " << Fixed::max( a, b ) << std::endl;
		std::cout << "5.05f / 2 = " << Fixed(5.05f) / Fixed(2) << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "--c: " << --c << std::endl;
		std::cout << "--c: " << --c << std::endl;
	}
	{
		std::cout << "\n\n~~~~~~~~ some other tests ~~~~~~~~~\n\n";
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );


		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << std::left << std::setw(22) << "a is greater then b? " << (a > b) << std::endl;
		std::cout << std::left << std::setw(22) << "a is lesser then b? " << (a < b) << std::endl;
		std::cout << std::left << std::setw(22) << "a is equal to b? " << (a == b) << std::endl;
		std::cout << std::left << std::setw(22) << "b is equal to d? " << (b == d) << std::endl;

		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a - b = " << (a - b) << std::endl;
		std::cout << "b * c = " << (b * c) << std::endl;
		std::cout << "a / b = " << (a / b) << std::endl;
		std::cout << "c / b = " << (c / b) << std::endl;
	}

	return 0;
}
