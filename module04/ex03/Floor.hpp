#ifndef FLOOR_HPP_
#define FLOOR_HPP_

#include "AMateria.hpp"

class Floor {
	private:
		AMateria* _materiaOnTheFloor[100];
	public:
		// canonical
		Floor(void);
		~Floor(void);
		Floor(const Floor &toCopy);
		Floor &operator=(const Floor &toAssign);

		// member functions
		void	putMateria(AMateria* materia);
		AMateria*	getMateria(int idx);
};

#endif
