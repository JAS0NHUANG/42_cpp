#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " destroid~~~";
}
