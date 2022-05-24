#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	std::cout << "~~~~~~Subject test~~~~~~\n";
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;

	std::cout << "~~~~~~WrongAnimal test~~~~~~\n";
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;
	const WrongAnimal* l = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "WrongCat addr: " << k << std::endl;
	std::cout << "WrongCat type: " << k->getType() << " " << std::endl;
	std::cout << "WrongAnimal addr: " << l << std::endl;
	std::cout << "WrongAnimal type: " << l->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "WrongCat makeSound: ";
	k->makeSound();
	std::cout << "WrongAnimal makeSound: ";
	l->makeSound();
	std::cout << std::endl;

	delete k;
	std::cout << std::endl;
	delete l;
	std::cout << std::endl;

	return (0);
}
