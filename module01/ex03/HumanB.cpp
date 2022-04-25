#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB(void) {
	/* debug
	std::cout << "\t(Debug)HumanB (" << this->name << ") is gone.\n";
	*/
}

void	HumanB::attack(void){
	if (this->weapon){
		std::cout << this->name << " attacks with their " << \
			this->weapon->getType() << "\n";
	}
	else {
		/* debug
		std::cout << "\t(Debug)" << this->name << " has no weapon yet.\n";
		*/
	}
	return ;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
