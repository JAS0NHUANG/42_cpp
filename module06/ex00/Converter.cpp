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
	if (c < 32 || c > 126)
		throw Converter::NonDisplayableException();
	return (static_cast<char>(c));
}

Converter::operator	int() const {
	char* ptr = NULL;
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
	std::cout << this->getStr() << "\n";
	try {
		std::cout << static_cast<char>(*this) << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << static_cast<int>(*this) << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	std::cout << static_cast<float>(*this) <<  "f\n";
	std::cout << static_cast<double>(*this) << "\n";
}
