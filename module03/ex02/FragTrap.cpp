#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called\n";
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
};

FragTrap::FragTrap( std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor with argument called\n";
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
};

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called\n";
};

void	FragTrap::highFiveGuys( void ) {
	std::cout << "This is a positive high fives requrest!\n";
};
