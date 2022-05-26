#include "Character.hpp"
#include "AMateria.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#else
# define VERBOSE 1
#endif

#include <iostream>

Character::Character(void) {
	VERBOSE && std::cout << "🧙 Character default constructor called\n";
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	VERBOSE && std::cout << "🧙 Character constructor with parameter called\n";
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::~Character(void) {
	VERBOSE && std::cout << "🧙 Character destructor called\n";
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
	}
}

Character::Character(const Character &toCopy) {
	VERBOSE && std::cout << "🧙 Character copy constructor called\n";
	int	i = 0;
	while (toCopy._inventory[i] && i < 4) {
		this->_inventory[i] = toCopy._inventory[i];
		i++;
	}
}

Character &Character::operator=(const Character &toAssign) {
	VERBOSE && std::cout << "🧙 Character copy assignment overload called\n";
	int	i = 0;
	while (toAssign._inventory[i] && i < 4) {
		this->_inventory[i] = toAssign._inventory[i];
		i++;
	}
	return (*this);
}

// getter / setter
std::string const &Character::getName(void) const {
	return (this->_name);
}

AMateria* Character::getMateria(int idx){
	return this->_inventory[idx];
};

// member functions
void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full. Can't equip another spell.\n";
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Not a valid index!\n";
		return ;
	}
	if (!this->_inventory[idx]) {
		std::cout << "No Materia in this slot!\n";
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Not a valid index!\n";
		return ;
	}
	if (!this->_inventory[idx]) {
		std::cout << "No Materia in this slot!\n";
		return ;
	}
	this->_inventory[idx]->use(target);
}
