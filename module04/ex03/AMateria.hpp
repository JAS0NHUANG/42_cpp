#ifndef MODULE04_EX03_AMATERIA_HPP_
#define MODULE04_EX03_AMATERIA_HPP_

# include <string>
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria(void);
		explicit AMateria(std::string const& type);
		virtual	~AMateria(void);
		AMateria(const AMateria& toCopy);
		AMateria &operator=(const AMateria& toAssign);

		std::string const & getType(void) const; //Returns the materia type

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif // MODULE04_EX03_AMATERIA_HPP_
