#include "Zombie.hpp"

Zombie::Zombie( void ){
	std::cout << "void zombie\t rised from the death~~~\n";
}

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << this->name << "\t rised from the death~~~\n";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << "\t destroid~~~\n";
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
