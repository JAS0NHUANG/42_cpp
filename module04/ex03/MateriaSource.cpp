#include <string>
#include <iostream>

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource default constructor called\n";
	for (int i = 0; i < 4; i++) {
		this->_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++) {
		if (this->_source[i] != NULL) {
			delete (this->_source[i]);
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &toCopy) {
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++) {
		if (toCopy._source[i]) {
			this->_source[i] = toCopy._source[i]->clone();
		}
	}
}
MateriaSource &MateriaSource::operator=(const MateriaSource &toAssign) {
	std::cout << "MateriaSource copy assignment overload called\n";
	for (int i = 0; i < 4; i++) {
		if (toAssign._source[i]) {
			this->_source[i] = toAssign._source[i]->clone();
		}
	}
	return (*this);
}

// member functions
void	MateriaSource::learnMateria(AMateria *toLearn) {
	for (int i = 0; i < 4; i++) {
		if (this->_source[i] == NULL) {
			this->_source[i] = toLearn->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_source[i] && this->_source[i]->getType().compare(type) == 0) {
			return (this->_source[i]->clone());
		}
	}
	if (type.compare("ice") == 0) {
		return (new Ice());
	}
	if (type.compare("cure") == 0) {
		return (new Ice());
	}
	return (0);
}
