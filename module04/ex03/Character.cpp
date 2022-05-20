// Copyright 2022 jahuang
#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>

Character::Character(void) {
	std::cout << "Character default constructor called\n";
}

~Character(void) {
	std::cout << "Character destructor called\n";
}

Character(const Character &toCopy) {
	std::cout << "Character copy constructor called\n";
	int	i = 0;
	while (toCopy._inventory[i] && i < 4) {
		this->_inventory[i] = toCopy._inventory[i];
		i++;
	}
}

Character &operator=(const Character &toAssign) {
	std::cout << "Character copy assignment overload called\n";
	int	i = 0;
	while (toAssign._inventory[i] && i < 4) {
		this->_inventory[i] = toAssign._inventory[i];
		i++;
	}
	return (*this);
}

// getter / setter
std::string const &getName(void) const {
	return (this->_name);
}

// member functions
void	equip(AMateria *m) {
	int	i = 0;
	while (toAssign._inventory[i] && i < 4) {
		i++;
	}
	if (i != 4) {
		this->_inventory[i] = m;
	} else {
		std::cout << "Inventory is full. Can't equip another spell.\n";
	}
}

void	unequip(int idx) {
	this->_inventory[idx] = NULL;
}
void	use(int idx, const ICharacter &target) {
}
