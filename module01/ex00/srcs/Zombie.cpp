#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << this->name << " rised from the death~~~";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " destroid~~~";
}
