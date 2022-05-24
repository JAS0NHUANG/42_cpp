#ifndef _WRONGCAT_HPP_
# define _WRONGCAT_HPP_

# include <string>

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &toCopy);
		WrongCat	&operator=(const WrongCat &toAssign);

		// member function
		void	makeSound(void) const;
};

#endif
