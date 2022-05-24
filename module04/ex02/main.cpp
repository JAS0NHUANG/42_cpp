#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	std::cout << "~~~~~~Subject test~~~~~~\n";
	// AAnimal abstract class is not instanciable 
	/*
	const AAnimal* test = new AAnimal();
	*/
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	i->printIdeas();
	j->printIdeas();

	/* should not have any leaks */
	delete(j);
	delete(i);
	std::cout << std::endl;

	std::cout << "~~~~~~AAnimal array~~~~~~\n";
	std::cout << std::endl;

	int	nbr = 4;
	AAnimal* animals[nbr];

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
		std::cout << "AAnimal type: " << \
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

	std::cout << "~~~~~~Kitty and her brain.~~~~~~\n";
	Cat kitty;
	std::cout << std::endl;

	kitty.addIdea("kitty idea 1");
	kitty.addIdea("kitty idea 2");
	kitty.printIdeas();
	std::cout << std::endl;

}
