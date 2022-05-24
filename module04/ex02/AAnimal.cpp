# include <iostream>

# include "AAnimal.hpp"

AAnimal::AAnimal( void ) {
	std::cout << "👾 AAnimal default constructor called\n";
	this->type = "AAnimal";
};

AAnimal::~AAnimal( void ) {
	std::cout << "👾 AAnimal destructor called\n";
};

AAnimal::AAnimal( const AAnimal &toCopy ) {
	std::cout << "👾 AAnimal copy constructor called\n";
	*this = toCopy;
};

AAnimal	&AAnimal::operator=( const AAnimal &toAssign ) {
	std::cout << "👾 AAnimal copy assignment overload called\n";
	this->type = toAssign.type;
	return (*this);
};

// getter
const std::string	AAnimal::getType( void ) const {
	return (this->type);
};

// member function
void	AAnimal::makeSound( void ) const {
	std::cout << "👾 AAnimal sound~~~\n";
};

void	AAnimal::addIdea(std::string idea) {
	(void)idea;
	return ;
}

void	AAnimal::printIdeas(void) const {
	return ;
}
