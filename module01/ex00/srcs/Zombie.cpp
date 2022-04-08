#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << this->name << "\t rose from the dead~~~\n";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << "\t vanished~~~\n";
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
