#include <iostream>

#include "ClapTrap.hpp"

// constructor and destructor
ClapTrap::ClapTrap( void ) {
	std::cout << "🐒 ClapTrap default constructor called\n";
	this->name = "Anonymous";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::ClapTrap( std::string name ) : name(name) {
	std::cout << "🐒 ClapTrap constructor with parameter called\n";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::~ClapTrap( void ){
	std::cout << this->name << "🐒 ClapTrap destructor called\n";
};

ClapTrap::ClapTrap( const ClapTrap &toCopy ){
	std::cout << "🐒 ClapTrap copy constructor called\n";
	*this = toCopy;
};

ClapTrap	&ClapTrap::operator=( const ClapTrap &toAssign ){
	std::cout << "🐒 ClapTrap copy assignment overload called\n";
	this->name = toAssign.name;
	this->hitPoints = toAssign.hitPoints;
	this->energyPoints = toAssign.energyPoints;
	this->attackDamage = toAssign.attackDamage;
	return (*this);
};

// getter
const std::string	&ClapTrap::getName( void ) const {
	return (this->name);
};

const unsigned int	&ClapTrap::getHitPoints( void ) const {
	return (this->hitPoints);
};

const unsigned int	&ClapTrap::getEnergyPoints( void ) const {
	return (this->energyPoints);
};

const unsigned int	&ClapTrap::getAttackDamage( void ) const {
	return (this->attackDamage);
};

// member functions
void	ClapTrap::attack( const std::string& target ){
	if (this->getEnergyPoints() == 0) {
		std::cout << "🐒 ClapTrap " << this->name << \
			" has no more energy points. Can't attack!\n";
		return ;
	} else if (this->getHitPoints() == 0) {
		std::cout << "🐒 ClapTrap " << this->name << \
			" is dead. Can't attack!\n";
		return ;
	}
	std::cout << "🐒 ClapTrap " << this->name << " attacks " << target << \
		", causing " << this->attackDamage << " points of damage!\n";
	this->energyPoints--;
};

void	ClapTrap::takeDamage( unsigned int amount ){
	std::cout << "🐒 ClapTrap " << this->name << " took " << amount << \
		" points of damage\n";
	amount > this->hitPoints ? \
		this->hitPoints = 0 : this->hitPoints -= amount;
};

void	ClapTrap::beRepaired( unsigned int amount ){
	if (this->getEnergyPoints() == 0) {
		std::cout << "🐒 ClapTrap " << this->name << \
			" has no more energy points. Can't be repaired!\n";
		return ;
	} else if (this->getHitPoints() == 0) {
		std::cout << "🐒 ClapTrap " << this->name << \
			" is dead. Can't be repaired!\n";
		return ;
	}
	std::cout << "🐒 ClapTrap " << this->name << \
		" is reparied for " << amount << " point(s)\n";
	this->hitPoints += amount;
	this->energyPoints--;
};
