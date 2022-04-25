#include "Zombie.hpp"

int	main( void )
{
	int	horde_size = 5;

	std::cout << "Summon the zombie horde with " << horde_size <<
	" zombies:\n";
	Zombie *the_horde = zombieHorde( horde_size, "ZzzzzombiE");
	std::cout << "Address of the first zombie: " << (void*)the_horde << "\n";
	std::cout << "Print the address of all zombies and tell them to announce:\n";
	for (int i = 0; i < horde_size; i++) {
		std::cout << "Address of the zombie No. " << i + 1 << ": " <<\
			(void*)&the_horde[i] << "\n";
		the_horde[i].announce();
	}
	std::cout << "Delete all zombies:\n";
	delete[] the_horde;

	std::cout << "\n ---------- this is a seperation line ---------- \n";

	horde_size = -1;
	std::cout << "Summon the zombie horde with " << horde_size << 
	" zombies:\n";
	the_horde = zombieHorde( horde_size, "ZzzzzombiE");
	if (the_horde) {
		std::cout << "\n";
		std::cout << "Address of the first zombie: " << (void*)the_horde << "\n";
		std::cout << "\n";
		std::cout << "Print the address of all zombies and tell them to announce:\n";
		for (int i = 0; i < horde_size; i++) {
			std::cout << "Address of the zombie No. " << i + 1 << ": " <<\
				(void*)&the_horde[i] << "\n";
			the_horde[i].announce();
		}
		std::cout << "\n";
		std::cout << "Delete all zombies:\n";
		delete[] the_horde;
	} else {
		std::cout << "Error when creating zombie horde.\n";
	}
	return (0);
}
