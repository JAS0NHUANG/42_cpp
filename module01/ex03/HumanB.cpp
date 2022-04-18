#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB(void) {
	std::cout << "\t(Debug)HumanB (" << this->name << ") is gone.\n";
}

void	HumanB::attack(void){
	if (!(this->weapon)){
		std::cout << "\t(Debug)" << this->name << " has no weapon yet.\n";
	}
	else {
		std::cout << this->name << " attacks with their " << this->weapon->getType() \
			<< "\n";
	}
	return ;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
