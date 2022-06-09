#include <iostream>
#include <string>
#include <cstdlib>

#include "Converter.hpp"

// canonical
Converter::Converter(void) : _str(NULL) {}

Converter::~Converter(void){}

Converter::Converter(const Converter &toCopy) {
	*this = toCopy;
}

Converter &Converter::operator=(const Converter &toAssign) {
	this->_str = toAssign.getStr();
	return (*this);
}

Converter::Converter(const std::string &str) : _str(str) {}

// getter
const std::string& Converter::getStr(void) const {
	return (this->_str);
}

// cast operators
Converter::operator	char() const {
	char* ptr = NULL;
	long double	c = 0;

	c = std::strtold(this->getStr().c_str(), &ptr);
	if (c != c)
		throw Converter::ImpossibleException();
	if (c < 32 || c > 126)
		throw Converter::NonDisplayableException();
	return (static_cast<char>(c));
}

Converter::operator	int() const {
	char* ptr = NULL;
	long double c = 0;

	c = std::strtold(this->getStr().c_str(), &ptr);
	if (c != c || c > 2147483647 || c < -214483648)
		throw Converter::ImpossibleException();
	return (std::strtold(this->getStr().c_str(), &ptr));
}

Converter::operator	float() const {
	char* ptr = NULL;
	return (std::strtof(this->getStr().c_str(), &ptr));
}

Converter::operator	double() const {
	char* ptr = NULL;
	return (std::strtod(this->getStr().c_str(), &ptr));
}

// exception handling
const char *Converter::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}

const char *Converter::ImpossibleException::what() const throw() {
	return ("impossible");
}

void	Converter::printResults(void) const {
	// print char
	try {
		std::cout << "char: ";
		char c = static_cast<char>(*this);
		std::cout << "\'" << c << "\'\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	// print int
	try {
		std::cout << "int: ";
		std::cout << static_cast<int>(*this) << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	// print float
	try {
		std::cout << "float: ";
		float f = static_cast<float>(*this);
		std::cout << f;
		((int)(f * 1000) % 1000 == 0) ? std::cout << ".0f\n" : std::cout << "f\n" ;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	// print double
	try {
		std::cout << "double: ";
		double d = static_cast<double>(*this);
		std::cout << d;
		((int)(d * 1000) % 1000 == 0) ? std::cout << ".0\n" : std::cout << "\n" ;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
}
