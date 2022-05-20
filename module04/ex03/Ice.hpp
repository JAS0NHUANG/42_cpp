#ifndef MODULE04_EX03_ICE_HPP_
#define MODULE04_EX03_ICE_HPP_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		~Ice(void);
		Ice(Ice const &toCopy);
		Ice &operator=(Ice const& toAssign);

		Ice*	clone(void) const;
		void	use(ICharacter &target);
};

#endif // MODULE04_EX03_ICE_HPP_

