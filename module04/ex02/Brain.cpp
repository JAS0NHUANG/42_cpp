#include <iostream>

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called\n";
}

Brain::Brain( const Brain &toCopy ) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = toCopy.ideas[i];
	}
}

Brain	&Brain::operator=( const Brain &toAssign) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = toAssign.ideas[i];
	}
	return (*this);
}
