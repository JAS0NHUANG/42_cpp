#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int		nbr;

	std::srand(std::time(0));
	nbr = std::rand() % 3;

	if (nbr == 0)
		return (new A());
	if (nbr == 1)
		return (new B());
	if (nbr == 2)
		return (new C());
	return (NULL);
}

void	identify(Base* p) {
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a) {
		std::cout << "A";
	} else if (b) {
		std::cout << "B";
	} else if (c) {
		std::cout << "C";
	} else {
		std::cout << "Not valid class";
	}
}

void	identify(Base& p) {
	try {
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A";
		return ;
	} catch (std::exception &e) {}
	try {
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B";
		return ;
	} catch (std::exception &e) {}
	try {
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C";
		return ;
	} catch (std::exception &e) {}
}

int main(void) {
	Base*	objectPtr = NULL;
	Base*	anotherObjectPtr = NULL;

	std::cout << "Create an instance of A, B, or C randomly.\n";
	objectPtr = generate();

	std::cout << "Identification of class by pointer.\n";
	identify(objectPtr);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Identification of class by reference.\n";
	Base&	objectRef = *objectPtr;
	identify(objectRef);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Identification of a non valid class.\n";
	identify(anotherObjectPtr);
	/* can't do this
	Base&	anotherObjectRef = *anotherObjectPtr;
	identify(anotherObjectRef);
	*/
	std::cout << "\n";

	delete objectPtr;

	return (0);
}
