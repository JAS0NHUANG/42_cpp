#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ){
	if (N <= 0 || N > 2147483647)
		return (NULL);

	Zombie *the_horde;
	// Allocate N Zombie objects in a single allocation.
	try {
		the_horde = new Zombie[N];
	} catch (std::bad_alloc const&){
		return (NULL);
	}

	// Initialize the zombies name.
	for ( int i = 0; i < N; i++) {
		the_horde[i].setName(name);
	}

	return (the_horde);
}
