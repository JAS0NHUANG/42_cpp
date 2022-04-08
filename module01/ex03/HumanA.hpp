#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		// constructor and destructor
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		// member functions
		void				attack(void);

	private:
		Weapon		&weapon;
		std::string	name;
};

#endif
