#include "Zombie.hpp"

int	main( void )
{
	/* Heap zombie by new */
	Zombie *heap_new = new Zombie("heap_zombie_new");
	heap_new->announce();
	
	/* Heap zombie by newZombie */
	Zombie *heap_newZombie = newZombie("heap_zombie_newZombie");
	heap_newZombie->announce();

	/* Stack zombie by randomChump */
	randomChump("stack_zomobie");

	delete(heap_new);
	delete(heap_newZombie);
	return (0);
}
