#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA (std::string name, Weapon &weapon): weapon(weapon) {
	this->name = name;
	this->weapon = weapon;
	return ;
}

HumanA::~HumanA(void){
	std::cout << "\t(Debug)HumanA (" << this->name << ") is gone!\n";
	return ;
}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon.getType() \
		<< "\n";
	return ;
}
