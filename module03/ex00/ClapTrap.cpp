#include <iostream>

#include "ClapTrap.hpp"

// constructor and destructor
ClapTrap::ClapTrap( void ) {
	std::cout << "default constructor called\n";
	this->name = "nameless";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::ClapTrap( std::string name ) : name(name) {
	std::cout << "constructor with string argument called\n";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
};

ClapTrap::~ClapTrap( void ){
	std::cout << "destructor called\n";
};

ClapTrap::ClapTrap( const ClapTrap &toCopy ){
	std::cout << "copy constructor called\n";
	*this = toCopy;
};

// copy assignment overload
ClapTrap	&ClapTrap::operator=( const ClapTrap &toAssign ){
	std::cout << "copy assignment overload called\n";
	this->name = toAssign.name;
	this->hitPoints = toAssign.hitPoints;
	this->energyPoints = toAssign.energyPoints;
	this->attackDamage = toAssign.attackDamage;
	return (*this);
};

// member functions
void		ClapTrap::attack( const std::string& target ){
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << \
		this->attackDamage << " points of damage!\n";
	this->energyPoints--;
};
void		ClapTrap::takeDamage( unsigned int amount ){
	std::cout << "I deal " << amount << " damage\n";
};
void		ClapTrap::beRepaired( unsigned int amount ){
	std::cout << "I reparied " << amount << " damage\n";
};
