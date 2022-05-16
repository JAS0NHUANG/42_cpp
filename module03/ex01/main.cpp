#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	printClapTrap( const ClapTrap &theClapTrap) {
	std::cout << "\n~~~~~~~" << theClapTrap.getName() << "'s info~~~~~~~\n";
	std::cout << theClapTrap.getName() << \
		"'s HP: " << theClapTrap.getHitPoints() << \
		", EP: " << theClapTrap.getEnergyPoints() << \
		", AD: " << theClapTrap.getAttackDamage() << "\n";
};

int	main( void ) {
	ClapTrap	clap1("clap1");
	ScavTrap	scav1("scav1");

	printClapTrap(clap1);
	printClapTrap(scav1);

	std::cout << "\n ⚔️	scav1 vs clap1!! FIGHT!! \n";

	std::cout << "\n clap1 attacks 11 times!! \n";
	for (int i = 0; i < 11; i++) {
		if (clap1.getEnergyPoints() != 0) {
			clap1.attack("scav1");
			scav1.takeDamage(clap1.getAttackDamage());
		} else {
			clap1.attack("scav1");
		}
	}

	printClapTrap(clap1);
	printClapTrap(scav1);
	std::cout << "\n";

	scav1.attack("clap1");
	clap1.takeDamage(scav1.getAttackDamage());

	printClapTrap(scav1);
	printClapTrap(clap1);

	std::cout << "\n ⚔️	clap1 and scav1 are being repaired!! \n";
	clap1.beRepaired(18);
	printClapTrap(clap1);
	std::cout << "\n";
	scav1.beRepaired(100);
	printClapTrap(scav1);
	std::cout << "\n";

	scav1.guardGate();

	std::cout << "\n";
}
