#include "HumanA.hpp"
#include <iostream>

// The ":weapon(weapon)" part set the dependency, because it can't be NULL.
HumanA::HumanA (std::string name, Weapon &weapon): weapon(weapon) {
	this->name = name;
	this->weapon = weapon;
	return ;
}

HumanA::~HumanA(void){
	/* debug
	std::cout << "\t(Debug)HumanA (" << this->name << ") is gone!\n";
	*/
	return ;
}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon.getType() \
		<< "\n";
	return ;
}
