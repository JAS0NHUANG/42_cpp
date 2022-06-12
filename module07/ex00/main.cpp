#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {

	std::cout << " ***** My own tests ***** \n";

	std::cout << " ~~~~~ Test with int ~~~~~ \n";
	int	a = 2;
	int	b = 42;

	std::cout << "Before swap:\n";
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << "\n";

	swap(a, b);

	std::cout << "After swap:\n";
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << "\n";

	std::cout << "Max value:\n";
	std::cout << max(a, b) << "\n";
	std::cout << "\n";

	std::cout << "Min value:\n";
	std::cout << min(a, b) << "\n";
	std::cout << "\n";

	std::cout << " ~~~~~ Test with string ~~~~~ \n";
	std::string str1 = "hello";
	std::string str2 = "world";

	std::cout << "Before swap:\n";
	std::cout << str1 << "\n";
	std::cout << str2 << "\n";
	std::cout << "\n";

	swap(str1, str2);

	std::cout << "After swap:\n";
	std::cout << str1 << "\n";
	std::cout << str2 << "\n";
	std::cout << "\n";

	std::cout << "Max value:\n";
	std::cout << ::max(str1, str2) << "\n";
	std::cout << "\n";

	std::cout << "Min value:\n";
	std::cout << ::min(str1, str2) << "\n";
	std::cout << "\n";



	std::cout << " ~~~~~ Test with char ~~~~~ \n";
	char c1 = '!';
	char c2 = 'o';

	std::cout << "Before swap:\n";
	std::cout << c1 << "\n";
	std::cout << c2 << "\n";
	std::cout << "\n";

	swap(c1, c2);

	std::cout << "After swap:\n";
	std::cout << c1 << "\n";
	std::cout << c2 << "\n";
	std::cout << "\n";

	std::cout << "Max value:\n";
	std::cout << max(c1, c2) << "\n";
	std::cout << "\n";

	std::cout << " ***** Tests in subject ***** \n";
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
