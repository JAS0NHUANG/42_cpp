#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
	private:
		AMateria* _source[4];

	public:
		// canonical
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource &toCopy);
		MateriaSource &operator=(const MateriaSource &toAssign);
		
		// member functions
		void	learnMateria(AMateria *toLearn);
		AMateria* createMateria(std::string const &type);
};

#endif
