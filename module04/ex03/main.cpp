#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

int	main() {
	Ice* newIce = new Ice();
	Cure* newCure = new Cure();
	Character* newChar = new Character("hoho");
	MateriaSource* newMateriaSource = new MateriaSource();
	Floor*	newFloor = new Floor();

	std::cout << newIce << "\n";
	std::cout << newIce->getType() << "\n";
	std::cout << newCure->getType() << "\n";
	newCure->use(*newChar);

	newChar->equip(newIce);
	newChar->equip(newCure);
	newChar->use(0, *newChar);
	newFloor->putMateria(newChar->getMateria(0));

	newChar->unequip(0);

	newMateriaSource->learnMateria(newCure);
	newChar->equip(newMateriaSource->createMateria("ice"));

	delete newChar;
	delete newFloor;
	delete newMateriaSource;
}

