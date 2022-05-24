#include <iostream>
#include "Floor.hpp"

Floor::Floor(void) {
	std::cout << "🪧 Floor default constructor called\n";
	for (int i = 0; i < 100; i++) {
		this->_materiaOnTheFloor[i] = NULL;
	}
}

Floor::~Floor(void) {
	std::cout << "🪧 Floor destructor called\n";
	for (int i = 0; i < 100; i++) {
		if (this->_materiaOnTheFloor[i] != NULL) {
			delete (this->_materiaOnTheFloor[i]);
		}
	}
}

Floor::Floor(const Floor &toCopy) {
	std::cout << "🪧 Floor copy constructor called\n";
	for (int i = 0; i < 100; i++) {
		if (toCopy._materiaOnTheFloor[i] != NULL) {
			this->_materiaOnTheFloor[i] = toCopy._materiaOnTheFloor[i]->clone();
		}
	}
}

Floor	&Floor::operator=(const Floor &toAssign) {
	std::cout << "🪧 Floor copy assignment overload called\n";
	for (int i = 0; i < 100; i++) {
		if (toAssign._materiaOnTheFloor[i] != NULL) {
			this->_materiaOnTheFloor[i] = toAssign._materiaOnTheFloor[i]->clone();
		}
	}
	return (*this);
}

// member functions
void	Floor::putMateria(AMateria* materia) {
	std::cout << "Put materia on the floor\n";
	for (int i = 0; i < 100; i++) {
		if (this->_materiaOnTheFloor[i] == NULL) {
			this->_materiaOnTheFloor[i] = materia;
			return ;
		}
	}
	std::cout << "No more space on the floor\n";
}

AMateria*	Floor::getMateria(int idx) {
	std::cout << "Get materia from the floor\n";
	return (this->_materiaOnTheFloor[idx]);
}
