#ifndef MODULE04_EX03_CURE_HPP_
#define MODULE04_EX03_CURE_HPP_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		~Cure(void);
		Cure(Cure const &toCopy);
		Cure &operator=(Cure const& toAssign);

		Cure*	clone(void) const;
		void	use(ICharacter& target);
};

#endif // MODULE04_EX03_CURE_HPP_

