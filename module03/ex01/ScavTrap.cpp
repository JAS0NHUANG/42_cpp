#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "🧐 ScavTrap default constructor called\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20 ;
};

ScavTrap::ScavTrap( std::string name) : ClapTrap(name) {
	std::cout << "🧐 ScavTrap constructor with parameter called\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20 ;
};

ScavTrap::~ScavTrap( void ) {
	std::cout << this->name << "🧐 ScavTrap destructor called\n";
};

ScavTrap::ScavTrap( const ScavTrap &toCopy ){
	std::cout << "🧐 ScavTrap copy constructor called\n";
	*this = toCopy;
};

ScavTrap			&ScavTrap::operator=( const ScavTrap &toAssign ){
	std::cout << "🧐 ScavTrap copy assignment overload called\n";
	this->name = toAssign.name;
	this->hitPoints = toAssign.hitPoints;
	this->energyPoints = toAssign.energyPoints;
	this->attackDamage = toAssign.attackDamage;
	return (*this);
};

// member functions
void	ScavTrap::attack( const std::string& target ){
	if (this->getEnergyPoints() == 0) {
		std::cout << "🧐 ScavTrap " << this->name << \
			" has no more energy points. Can't attack!\n";
		return ;
	} else if (this->getHitPoints() == 0) {
		std::cout << "🧐 ScavTrap " << this->name << \
			" is dead. Can't attack!\n";
		return ;
	}
	std::cout << "🧐 ScavTrap " << this->name << " attacks " << target << \
		", causing " << this->getAttackDamage() << " points of damage!\n";
	this->energyPoints--;
}

void	ScavTrap::guardGate( void ) {
	if (this->getEnergyPoints() == 0) {
		std::cout << "🧐 ScavTrap " << this->name << \
			" has no more energy points. Can't guard the Gate!\n";
		return ;
	}
	std::cout << "🧐 ScavTrap(" << this->name << \
		"):I'm now in Gate keeper mode\n";
	this->energyPoints--;
};
