#include <iostream>

#include "ClapTrap.hpp"

// constructor and destructor
ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap default constructor called\n";
	this->name = "Anonymous";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::ClapTrap( std::string name ) : name(name) {
	std::cout << "ClapTrap constructor with parameter called\n";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::~ClapTrap( void ){
	std::cout << "ClapTrap destructor called\n";
};

ClapTrap::ClapTrap( const ClapTrap &toCopy ){
	std::cout << "ClapTrap copy constructor called\n";
	*this = toCopy;
};

// copy assignment overload
ClapTrap			&ClapTrap::operator=( const ClapTrap &toAssign ){
	std::cout << "ClapTrap copy assignment overload called\n";
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
const int			&ClapTrap::getHitPoints( void ) const {
	return (this->hitPoints);
};

const int			&ClapTrap::getEnergyPoints( void ) const {
	return (this->energyPoints);
};
const int			&ClapTrap::getAttackDamage( void ) const {
	return (this->attackDamage);
};

// member functions
void				ClapTrap::attack( const std::string& target ){
	std::cout << "ClapTrap " << this->name << " attacks " << target << \
		", causing " << this->attackDamage << " points of damage!\n";
	this->energyPoints--;
};
void				ClapTrap::takeDamage( unsigned int amount ){
	std::cout << "I took " << amount << " damage\n";
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
};

void		ClapTrap::beRepaired( unsigned int amount ){
	std::cout << "I'm reparied for " << amount << " point\n";
	this->hitPoints++;
};
