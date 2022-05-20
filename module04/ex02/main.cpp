#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	std::cout << "~~~~~~Subject test~~~~~~\n";
	// can't instantiate Animal object
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	// delete(meta);
	delete(j);
	delete(i);

	std::cout << "~~~~~~WrongAnimal test~~~~~~\n";

	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	delete(k);
}
