// Copyright 2022 jahuang
#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>

Character::Character(void) {
	std::cout << "🧙 Character default constructor called\n";
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	std::cout << "🧙 Character constructor with parameter called\n";
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::~Character(void) {
	std::cout << "🧙 Character destructor called\n";
	int	i = 0;
	while (this->_inventory[i] != NULL) {
		delete this->_inventory[i];
		i++;
	}
}

Character::Character(const Character &toCopy) {
	std::cout << "🧙 Character copy constructor called\n";
	int	i = 0;
	while (toCopy._inventory[i] && i < 4) {
		this->_inventory[i] = toCopy._inventory[i];
		i++;
	}
}

Character &Character::operator=(const Character &toAssign) {
	std::cout << "🧙 Character copy assignment overload called\n";
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
	int	i = 0;
	while (this->_inventory[i] && i < 4) {
		i++;
	}
	if (i != 4) {
		this->_inventory[i] = m;
	} else {
		std::cout << "Inventory is full. Can't equip another spell.\n";
	}
}

void	Character::unequip(int idx) {
	std::cout << "Unequip " << this->_inventory[idx]->getType() << "\n";
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	this->_inventory[idx]->use(target);
}
