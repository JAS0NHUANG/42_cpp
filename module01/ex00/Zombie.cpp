#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << this->name << " rose from the hell~~~\n";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " died~~~(again)\n";
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
