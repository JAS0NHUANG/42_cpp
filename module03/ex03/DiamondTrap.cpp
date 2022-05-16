#include "DiamondTrap.hpp"
#include <iostream>

// constructor / destructor
DiamondTrap::DiamondTrap( void ) :
	ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "💎 DiamondTrap default constructor called\n";
	this->name = "anonymous";
	ClapTrap::name = "anonymous_clap_name";
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
};

DiamondTrap::DiamondTrap( std::string name ) :
	ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "💎 DiamondTrap constructor with parameter called\n";
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();

};

DiamondTrap::DiamondTrap( DiamondTrap const &toCopy ) :
	ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "💎 DiamondTrap copy constructor called\n";
	*this = toCopy;
};


DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &toAssign ){
	std::string	name = toAssign.name;
	std::cout << "💎 DiamondTrap copy assignment overload called\n";
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hitPoints = toAssign.hitPoints;
	this->energyPoints = toAssign.energyPoints;
	this->attackDamage = toAssign.attackDamage;
	return (*this);
};

DiamondTrap::~DiamondTrap( void ) {
	std::cout << this->name << "💎  DiamondTrap destructor called\n";
};

// member functions
void	DiamondTrap::attack( const std::string& target ){
	ScavTrap::attack(target);
}
void		DiamondTrap::whoAmI( void ) const {
	std::cout << "My name is " << this->name << "(💎DiamondTrap name) or " << \
		this->ClapTrap::name << "(🐒ClapTrap name)?\n";
};

const std::string	&DiamondTrap::getName( void ) const {
	return (this->name);
};
