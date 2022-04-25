#include <string>
#include <iostream>
#include <iomanip>

int	main( void )
{
	// Original string
	std::string	stringORG = "HI THIS IS BRAIN";
	// A pointer to the string
	std::string	*stringPTR = &stringORG;
	// A reference to the string
	std::string	&stringREF = stringORG;

	// print address
	std::cout << "\n|----------print address--------------------------------->\n";
	std::cout << std::left << std::setw(42) << \
		"The address of the string:" << &stringORG << "\n";
	std::cout << std::left << std::setw(42) << \
		"The address held by stringPTR:" << stringPTR << "\n";
	std::cout << std::left << std::setw(42) << \
		"The address held by stringREF:" << &stringREF << "\n";

	// print string values
	std::cout << "\n|----------print values---------------------------------->\n";
	std::cout << std::left << std::setw(42) << \
		"The value of the string:" << stringORG << "\n";
	std::cout << std::left << std::setw(42) << \
		"The value pointed to by stringPTR:" << *stringPTR << "\n";
	std::cout << std::left << std::setw(42) << \
		"The value pointed to by stringREF:" << stringREF << "\n";

	/* You can play around by changing the string's value with the REF:
	stringREF = "THIS IS NOT BRAIN!!!!";
	// print address
	std::cout << "\n|----------print address--------------------------------->\n";
	std::cout << std::left << std::setw(42) << \
		"The address of the string:" << &stringORG << "\n";
	std::cout << std::left << std::setw(42) << \
		"The address held by stringPTR:" << stringPTR << "\n";
	std::cout << std::left << std::setw(42) << \
		"The address held by stringREF:" << &stringREF << "\n";

	// print string values
	std::cout << "\n|----------print values---------------------------------->\n";
	std::cout << std::left << std::setw(42) << \
		"The value of the string:" << stringORG << "\n";
	std::cout << std::left << std::setw(42) << \
		"The value pointed to by stringPTR:" << *stringPTR << "\n";
	std::cout << std::left << std::setw(42) << \
		"The value pointed to by stringREF:" << stringREF << "\n";
	*/


	return (0);
}
