#include "DiamondTrap.hpp"
#include <iostream> 


// constructor / destructor
DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap() {
	this->name = "nameless";
	ClapTrap::name = "nameless_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
};

DiamondTrap::DiamondTrap( std::string name ) : ScavTrap(name), FragTrap(name) {
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

};
DiamondTrap::DiamondTrap( DiamondTrap const &toCopy ) : ClapTrap(), ScavTrap(), FragTrap() {
	*this = toCopy;
};
DiamondTrap::~DiamondTrap( void ) {};


// member functions
void		DiamondTrap::whoAmI( void ) const {
	std::cout << "My name is " << this->name << "(DiamondTrap name) or " << this->ClapTrap::name << "(ClapTrap name)?\n";
};

const std::string	&DiamondTrap::getName( void ) const {
	return (this->name);
};
