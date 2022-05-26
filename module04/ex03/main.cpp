#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

int	main() {
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
	}
	std::cout << std::endl;

	std::cout << "~~~~~ my test ~~~~~\n";
	{
		Ice* newIce = new Ice();
		Cure* newCure = new Cure();
		Ice* newIce1 = new Ice();
		Cure* newCure1 = new Cure();
		Ice* newIce2 = new Ice();
		Character* newCharA = new Character("Char A");
		Character* newCharB = new Character("Char B");
		Floor*	newFloor = new Floor();

		std::cout << "Ice addr: " << newIce << "\n";
		std::cout << "Ice type: " << newIce->getType() << "\n";
		std::cout << "Cure addr: " << newCure << "\n";
		std::cout << "Cure type: " << newCure->getType() << "\n";
		std::cout << std::endl;

		std::cout << "~~~~~ use, equip, and unequip ~~~~~\n";
		std::cout << "Just using the newCure spell: \n";
		newCure->use(*newCharA);

		std::cout << "Char A equip Ice\n";
		newCharA->equip(newIce);
		std::cout << "Char A equip Cure\n";
		newCharA->equip(newCure);
		std::cout << "Char A equip Ice1\n";
		newCharA->equip(newIce1);
		std::cout << "Char A equip Cure1\n";
		newCharA->equip(newCure1);
		std::cout << "Char A equip Ice2\n";
		newCharA->equip(newIce2);
		std::cout << std::endl;

		newCharA->use(0, *newCharB);
		newCharA->use(-1, *newCharB);
		newCharB->use(0, *newCharA);
		std::cout << std::endl;


		std::cout << "Char A unequip slot 0 materia.\n";
		newFloor->putMateria(newCharA->getMateria(0));
		newFloor->putMateria(newCharA->getMateria(99));
		newCharA->unequip(0);

		delete newCharA;
		delete newCharB;
		delete newFloor;
		delete newIce2;
	}
}

