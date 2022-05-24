#include <iostream>

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "🧠 Brain default constructor called\n";
}

Brain::~Brain( void ) {
	std::cout << "🧠 Brain destructor called\n";
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

void	Brain::addIdea(std::string idea) {
	int i = 0;
	while (!this->ideas[i].empty()) {
		i++;
	}
	this->ideas[i] = idea;
}

void	Brain::printIdeas( void ) const {
	int i = 0;
	if (this->ideas[i].empty()) {
		std::cout << "I have no ideas!!\n";
	}
	while (!this->ideas[i].empty()) {
		std::cout << this->ideas[i];
		if (this->ideas[i + 1].empty()) {
			std::cout << "\n";
		} else {
			std::cout << ", ";
		}
		i++;
	}
}
