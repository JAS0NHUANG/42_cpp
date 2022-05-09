#include <iostream>

#include "ClapTrap.hpp"

void	printClapTrap( const ClapTrap &theClapTrap) {
	std::cout << "\n~~~~~~~" << theClapTrap.getName() << "'s info~~~~~~~\n";
	std::cout << theClapTrap.getName() << "'s HP: " << theClapTrap.getHitPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s EP: " << theClapTrap.getEnergyPoints() << "\n";
	std::cout << theClapTrap.getName() << "'s AD: " << theClapTrap.getAttackDamage() << "\n";
};

int	main( void ) {
	ClapTrap	blabla("blabla");
	ClapTrap	bloblo = blabla;
	ClapTrap	blibli;

	printClapTrap(blabla);
	blabla.attack("bloblo");
	printClapTrap(blabla);
	std::cout << "\n";

	printClapTrap(bloblo);
	std::cout << "(this is a blabla copy)\n";
	bloblo.takeDamage(99);
	std::cout << "(this is also a blabla copy)\n";
	printClapTrap(bloblo);
	printClapTrap(blabla);

	printClapTrap(blibli);

}
