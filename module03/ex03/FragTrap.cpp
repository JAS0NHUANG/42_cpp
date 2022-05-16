#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "🐸 FragTrap default constructor called\n";
	this->setHP();
	this->setEP();
	this->setAD();
};

FragTrap::FragTrap( std::string name) : ClapTrap(name) {
	std::cout << "🐸 FragTrap constructor with parameter called\n";
	this->setHP();
	this->setEP();
	this->setAD();
};

FragTrap::~FragTrap( void ) {
	std::cout << this->name <<  "🐸 FragTrap destructor called\n";
};

FragTrap			&FragTrap::operator=( const FragTrap &toAssign ){
	std::cout << "🐸 FragTrap copy assignment overload called\n";
	this->name = toAssign.name;
	this->hitPoints = toAssign.hitPoints;
	this->energyPoints = toAssign.energyPoints;
	this->attackDamage = toAssign.attackDamage;
	return (*this);
};

// setter
void	FragTrap::setHP( void ){ this->hitPoints = 100; };

void	FragTrap::setEP( void ){ this->energyPoints = 100; };

void	FragTrap::setAD( void ){ this->attackDamage = 30; };

// member functions
void	FragTrap::attack( const std::string& target ){
	if (this->getEnergyPoints() == 0) {
		std::cout << "🐸 FragTrap " << this->name << \
			" has no more energy points. Can't attack!\n";
		return ;
	} else if (this->getHitPoints() == 0) {
		std::cout << "🐸 FragTrap " << this->name << \
			" is dead. Can't attack!\n";
		return ;
	}
	std::cout << "🐸 FragTrap " << this->name << " attacks " << target << \
		", causing " << this->getAttackDamage() << " points of damage!\n";
	this->energyPoints--;
}

void	FragTrap::highFivesGuys( void ) {
	if (this->getEnergyPoints() == 0) {
		std::cout << "🐸 FragTrap " << this->name << \
			" has no more energy points. Can't guard the Gate!\n";
		return ;
	}
	std::cout << "🐸 FragTrap(" << this->name << "):Yehhhh~~ High Five!\n";
	this->energyPoints--;
};
