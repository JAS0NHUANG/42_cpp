#include <iostream>

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( 10 );
	Fixed c(42.42f);
	Fixed d( b );

	a = Fixed( 1234.4321f);

	std::cout << (a.getRawBits() >> 8) << std::endl;
	std::cout << a;
	std::cout << (b.getRawBits() >> 8) << std::endl;
	std::cout << b;
	std::cout << (c.getRawBits() >> 8) << std::endl;
	std::cout << c;
	std::cout << (d.getRawBits() >> 8) << std::endl;
	std::cout << d;

	std::cout << 9.9f << std::endl;
	std::cout << (1 << 8) << std::endl;
	return 0;
}
