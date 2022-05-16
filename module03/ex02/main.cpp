#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	FragTrap	frag1("frag1");

	printClapTrap(clap1);
	printClapTrap(scav1);
	printClapTrap(frag1);

	std::cout << "\nfrag and scav's actions:\n";
	scav1.guardGate();
	frag1.highFivesGuys();

	std::cout << "\n ⚔️	clap1 vs scav1 vs frag1!! FIGHT!! \n";

	clap1.attack("scav1");
	scav1.takeDamage(clap1.getAttackDamage());
	printClapTrap(clap1);
	printClapTrap(scav1);
	std::cout << "\n";

	scav1.attack("frag1");
	frag1.takeDamage(scav1.getAttackDamage());
	printClapTrap(scav1);
	printClapTrap(frag1);
	std::cout << "\n";

	frag1.attack("clap1");
	clap1.takeDamage(frag1.getAttackDamage());
	printClapTrap(frag1);
	printClapTrap(clap1);
	std::cout << "\n";
}
