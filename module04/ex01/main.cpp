#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	/*
	std::cout << "~~~~~~Subject test~~~~~~\n";
	const Animal* test = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << test->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	i->printIdeas();
	j->printIdeas();

	delete(j);
	delete(i);
	delete(test);
	std::cout << std::endl;

	std::cout << "~~~~~~Animal array~~~~~~\n";
	std::cout << std::endl;

	int	nbr = 4;
	Animal* animals[nbr];

	std::cout << "------create dogs and cats-------\n" <<  std::endl;
	for (int i = 0; i < nbr; i++) {
		std::cout << i << std::endl;
		if (i < (nbr / 2)) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	std::cout << std::endl;

	std::cout << "-------Dogs and cats making sound.-------\n" <<  std::endl;
	for (int i = 0; i < nbr; i++) {
		std::cout << "Animal type: " << \
			animals[i]->getType() << " " << std::endl;
		animals[i]->makeSound();
		animals[i]->addIdea("idea1");
		animals[i]->addIdea("idea2");
		animals[i]->printIdeas();
	}
	std::cout << std::endl;

	std::cout << "-------Delete dogs and cats.-------\n";
	for (int i = 0; i < nbr; i++) {
		delete animals[i];
	}
	std::cout << std::endl;
*/
	std::cout << "~~~~~~Kitty and Cutee's brains~~~~~~\n";
	std::cout << "(deep copy test)\n";
	Cat kitty;
	std::cout << std::endl;

	kitty.addIdea("kitty idea 1");
	kitty.addIdea("kitty idea 2");
	std::cout << std::endl;

	Cat cutee(kitty);
	cutee.addIdea("cutee idea 1");
	kitty.printIdeas();
	cutee.printIdeas();
	std::cout << std::endl;
}
