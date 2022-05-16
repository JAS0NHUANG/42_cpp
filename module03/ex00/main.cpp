#include <iostream>

#include "ClapTrap.hpp"

void	printClapTrap( const ClapTrap &theClapTrap) {
	std::cout << "\n~~~~~~~" << theClapTrap.getName() << "'s info~~~~~~~\n";
	std::cout << theClapTrap.getName() << "'s HP: " << \
		theClapTrap.getHitPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s EP: " << \
		theClapTrap.getEnergyPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s AD: " << \
		theClapTrap.getAttackDamage() << "\n";
};

int	main( void ) {
	ClapTrap	clap1("clap1");
	ClapTrap	clap2("clap2");

	printClapTrap(clap1);
	printClapTrap(clap2);

	std::cout << "\n ⚔️	clap1 attack clap2!! \n";
	clap1.attack("clap2");
	clap2.takeDamage(clap1.getAttackDamage());
	printClapTrap(clap1);
	printClapTrap(clap2);
	std::cout << "\n";

	std::cout << "\n clap1 attacks clap2 11 times!! \n";
	for (int i = 0; i < 11; i++) {
		if (clap1.getEnergyPoints() != 0) {
			clap1.attack("clap2");
			clap2.takeDamage(clap1.getAttackDamage());
		} else {
			clap1.attack("clap2");
		}
	}

	std::cout << "\n ⚔️	clap1 and clap2 took some damages!! \n";
	clap1.takeDamage(8);
	printClapTrap(clap1);
	std::cout << "\n";
	clap2.takeDamage(19);
	printClapTrap(clap2);

	std::cout << "\n ⚔️	clap1 and clap2 are being repaired!! \n";
	clap1.beRepaired(18);
	printClapTrap(clap1);
	std::cout << "\n";
	clap2.beRepaired(100);
	printClapTrap(clap2);


	std::cout << "\n";
}
