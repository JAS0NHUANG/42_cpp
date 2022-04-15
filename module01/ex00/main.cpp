#include "Zombie.hpp"

int	main( void )
{
	// Create a zombie on the heap with new.
	Zombie *heap_z = new Zombie("Heap Z");
	heap_z->announce();

	// Create a zombie on the heap with newZombie function.
	Zombie *new_heap_z = newZombie("New Heap Z");

	// Create a zombie on the stack.
	Zombie stack_z = Zombie("Stack Z");

	// Delete(free) the heap_z
	delete(heap_z);
	heap_z->announce();

	// Delete(free) the new_heap_z
	delete(new_heap_z);

	// stack_z will be destroied automaticly when exiting the scope.

	return (0);
}
