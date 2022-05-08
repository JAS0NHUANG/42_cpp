#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

void	printTrap( const ClapTrap &theTrap) {
	std::cout << theTrap.getName() << " hit points: " << theTrap.getHitPoints() << "\n";
	std::cout << theTrap.getName() << " energy points: " << theTrap.getEnergyPoints() << "\n";
	std::cout << theTrap.getName() << " attack damage: " << theTrap.getAttackDamage() << "\n";

};

int	main( void ) {
	ClapTrap	blablabla;
	ClapTrap	b = blablabla;
	ScavTrap	kk("abc");
	FragTrap	oo;

	blablabla.attack("oooo");
	b.attack("yoyo");

	printTrap(kk);
	kk.attack("yoyo");
	printTrap(kk);
	kk.guardGate();
	oo.highFiveGuys();
}
