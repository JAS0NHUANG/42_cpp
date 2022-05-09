#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

void	printClapTrap( const ClapTrap &theClapTrap) {
	std::cout << "\n" << theClapTrap.getName() << "'s info\n";
	std::cout << theClapTrap.getName() << "'s HP: " << theClapTrap.getHitPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s EP: " << theClapTrap.getEnergyPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s AD: " << theClapTrap.getAttackDamage() << "\n";

};

int	main( void ) {
	ClapTrap	blablabla;
	ClapTrap	b = blablabla;
	ScavTrap	kk("abc");

	blablabla.attack("oooo");
	b.attack("yoyo");

	printTrap(kk);
	kk.attack("yoyo");
	printTrap(kk);
	kk.guardGate();
}
