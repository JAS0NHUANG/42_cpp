#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ){
	if (N <= 0) return (NULL);

	Zombie *the_horde = new Zombie[N];

	for ( int i = 0; i < N; i++) {
		the_horde[i].setName(name);
	}

	return (the_horde);
}
