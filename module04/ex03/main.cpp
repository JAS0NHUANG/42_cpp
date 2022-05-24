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
	std::cout << std::endl;
	Cure* newCure = new Cure();
	std::cout << std::endl;
	Character* newChar = new Character("hoho");
	std::cout << std::endl;
	MateriaSource* newMateriaSource = new MateriaSource();
	std::cout << std::endl;
	Floor*	newFloor = new Floor();
	std::cout << std::endl;

	std::cout << "Ice addr: " << newIce << "\n";
	std::cout << "Ice type: " << newIce->getType() << "\n";
	std::cout << std::endl;
	std::cout << "Cure addr: " << newCure << "\n";
	std::cout << "Cure type: " << newCure->getType() << "\n";
	std::cout << std::endl;

	std::cout << "~~~~~ use, equip, and unequip ~~~~~\n";
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
	std::cout << std::endl;

	std::cout << "~~~~~ test in subject ~~~~~\n";
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}

