#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include "Weapon.hpp"

class HumanA {
	public:
		// constructor and destructor
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		// member functions
		void				attack(void);

	private:
		// Since HumanA will always be armed.
		// The private attribute Weapon is set as a reference.
		// Because a reference can never point to NULL.
		Weapon		&weapon;
		std::string	name;
};

#endif
