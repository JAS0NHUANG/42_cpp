#include "Zombie.hpp"

int	main( void )
{
	int	horde_size = 5;
	Zombie *the_horde = zombieHorde( horde_size, "hello");
	std::cout << "Address of the first zombie: " << (void*)the_horde << "\n";
	for (int i = 0; i < horde_size; i++) {
		std::cout << "Address ot the zombie No. " << i + 1 << ": " <<\
			(void*)&the_horde[i] << "\n";
		std::cout << "No. " << i + 1 << " ";
		the_horde[i].announce();
	}

	delete[] the_horde;

	return (0);
}
