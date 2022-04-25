#include "Zombie.hpp"

int	main( void )
{
	// Create a zombie on the heap with new.
	// Make it announce then delete it.
	Zombie *heap_z = new Zombie("Heap Z");
	heap_z->announce();
	delete(heap_z);

	std::cout << "\n ---------- this is a seperation line ---------- \n\n";
	// Create a zombie on the heap with newZombie function.
	// Make it announce then delete it.
	Zombie *new_heap_z = newZombie("New Heap Z");
	new_heap_z->announce();
	delete(new_heap_z);

	std::cout << "\n ---------- this is a seperation line ---------- \n\n";
	// Call the function randomChump.
	// Random Z will be created and announce itself.
	// It'll be destroied automaticly when exiting the scope.
	randomChump("Random Z");


	std::cout << "\n ---------- this is a seperation line ---------- \n\n";
	// Create a zombie on the stack.
	// Make it announce. It'll be destroied automaticly when exiting the scope.
	Zombie stack_z = Zombie("Stack Z");

	return (0);
}
