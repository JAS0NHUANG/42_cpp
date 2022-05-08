#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor called\n";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
};

ScavTrap::ScavTrap( std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor with argument called\n";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
};

ScavTrap::~ScavTrap( void ) {};

void	ScavTrap::guardGate( void ) {
	std::cout << "I'm now in Gate keeper mode\n";
};
