#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

# include <string>
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(std::string const& type);
		~AMateria(void);
		AMateria(AMateria &toCopy);
		AMateria &operator=(AMateria &toAssign);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
