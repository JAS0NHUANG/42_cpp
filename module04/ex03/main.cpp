#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main() {
	Ice* newIce = new Ice();
	Cure* newCure = new Cure();
	Character* newChar = new Character("hoho");
	MateriaSource* newMateriaSource = new MateriaSource();

	std::cout << newIce->getType() << "\n";
	std::cout << newCure->getType() << "\n";
	newCure->use(*newChar);

	newChar->equip(newIce);
	newChar->use(0, *newChar);

	newMateriaSource->createMateria("ice");

	delete newChar;
}

