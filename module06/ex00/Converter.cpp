#include "Converter.hpp"

bool	isNanOrInf(std::string str) {
	if (!str.compare("nan") || !str.compare("nanf") || \
		!str.compare("+nan") || !str.compare("+nanf") || \
		!str.compare("-nan") || !str.compare("-nanf") || \
		!str.compare("inf") || !str.compare("inff") || \
		!str.compare("-inf") || !str.compare("+inf") || \
		!str.compare("-inff") || !str.compare("+inff")){
		return (true);
	}
	return (false);
}

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
	std::string str = this->getStr();
	char* ptr = NULL;
	long double	c = 0;

	c = std::strtold(str.c_str(), &ptr);
	if (c != c || str.c_str() == ptr)
		throw Converter::ImpossibleException();
	if (c < 32 || c > 126)
		throw Converter::NonDisplayableException();
	return (static_cast<char>(c));
}

Converter::operator	int() const {
	std::string str = this->getStr();
	char* ptr = NULL;
	long double c = 0;

	c = std::strtold(str.c_str(), &ptr);
	if (c != c || str.c_str() == ptr || \
		c > std::numeric_limits<int>::max() || \
		c < -std::numeric_limits<int>::max())
		throw Converter::ImpossibleException();
	return (c);
}

Converter::operator	float() const {
	std::string str = this->getStr();
	char* ptr = NULL;
	long double c = 0;

	if (isNanOrInf(str) == true)
		return (std::strtod(this->getStr().c_str(), &ptr));
	c = std::strtold(str.c_str(), &ptr);
	if (c != c || str.c_str() == ptr || \
		c > std::numeric_limits<float>::max() || \
		c < -std::numeric_limits<float>::max())
		throw Converter::ImpossibleException();
	return (c);
}

Converter::operator	double() const {
	std::string str = this->getStr();
	char* ptr = NULL;
	long double c = 0;

	if (isNanOrInf(str) == true)
		return (std::strtod(this->getStr().c_str(), &ptr));
	c = std::strtold(str.c_str(), &ptr);
	if (c != c || str.c_str() == ptr || \
		c > std::numeric_limits<double>::max() || \
		c < -std::numeric_limits<double>::max())
		throw Converter::ImpossibleException();
	return (c);
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

