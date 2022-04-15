#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_

# include "Weapon.hpp"

class HumanB {
	public:
		// constructor and destructor
		HumanB(std::string name);
		~HumanB(void);

		// getters and setters
		void				setWeapon(Weapon &weapon);

		// member functions
		void				attack(void);

	private:
		Weapon		*weapon;
		std::string	name;
};

#endif
