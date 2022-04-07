#include "Zombie.hpp"

Zombie* newZombie( std::string name)
{
	Zombie* zombie_on_the_heap;

	zombie_on_the_heap = new Zombie(name);
	return (zombie_on_the_heap);
}
