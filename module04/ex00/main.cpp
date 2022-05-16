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
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "~~~~~~Cat / Dog with names~~~~~~\n";
	const Animal* a = new Dog("Shiba");
	std::cout << std::endl;
	const Animal* b = new Cat("Copy");
	std::cout << std::endl;

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;
	std::cout << std::endl;

	delete a;
	delete b;
	std::cout << std::endl;

	std::cout << "~~~~~~WrongAnimal test~~~~~~\n";
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* l = new WrongAnimal();
	std::cout << std::endl;

	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound();
	l->makeSound();

	delete k;
	delete l;
}
