#include "Zombie.hpp"

Zombie::Zombie( void ){
	std::cout << "Nameless zombie rose from the dead~~~\n";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " died~~~(again)\n";
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
