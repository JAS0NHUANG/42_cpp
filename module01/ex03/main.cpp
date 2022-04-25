#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// testing main from the subject.
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	/* debug
	std::cout << "\n ---------- The seperation line ---------- \n\n";
	*/
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		/* debug
		jim.attack();
		*/
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
