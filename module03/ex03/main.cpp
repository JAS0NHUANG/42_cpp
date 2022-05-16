#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	printClapTrap( const ClapTrap &theClapTrap) {
	std::cout << "\n~~~~~~~" << theClapTrap.getName() << "'s info~~~~~~~\n";
	std::cout << theClapTrap.getName() << \
		"'s HP: " << theClapTrap.getHitPoints() << \
		", EP: " << theClapTrap.getEnergyPoints() << \
		", AD: " << theClapTrap.getAttackDamage() << "\n";
};

void	printDiamondTrap( const DiamondTrap &theClapTrap) {
	std::cout << "\n~~~~~~~" << theClapTrap.getName() << "'s info~~~~~~~\n";
	std::cout << theClapTrap.getName() << \
		" (aka: " << theClapTrap.ClapTrap::getName() << ")" << \
		"'s HP: " << theClapTrap.getHitPoints() << \
		", EP: " << theClapTrap.getEnergyPoints() << \
		", AD: " << theClapTrap.getAttackDamage() << "\n";
};

int	main( void ) {
	std::cout << "Create all Traps:\n";
	ClapTrap	clap1("clap1");
	ScavTrap	scav1("scav1");
	FragTrap	frag1("frag1");
	DiamondTrap	dmd1("dmd1");

	printClapTrap(clap1);
	printClapTrap(scav1);
	printClapTrap(frag1);
	printDiamondTrap(dmd1);

	std::cout << "\nfrag and scav's actions:\n";
	scav1.guardGate();
	frag1.highFivesGuys();

	std::cout << "\nDiamond can do all:\n";
	dmd1.DiamondTrap::guardGate();
	dmd1.DiamondTrap::highFivesGuys();
	dmd1.DiamondTrap::whoAmI();

	std::cout << "\n ⚔️	dmd1 vs frag1!! FIGHT!! \n";

	dmd1.attack("frag1");
	frag1.takeDamage(dmd1.getAttackDamage());
	printClapTrap(dmd1);
	printClapTrap(frag1);

	std::cout << "\n";
	frag1.attack("dmd1");
	dmd1.takeDamage(frag1.getAttackDamage());
	printClapTrap(dmd1);
	printClapTrap(frag1);

	std::cout << "\nCall the distructors before exit the main function\n";
}
