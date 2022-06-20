#include <iostream>

#include "MutantStack.hpp"


int	main() {
	MutantStack<int> mStack;
	MutantStack<int>::iterator	it;	
	MutantStack<int>::iterator	ite;	

	std::cout << "Push number 11 into the mutant stack.\n";
	mStack.push(11);
	std::cout << "Mutant stack size: " << mStack.size() << "\n";

	std::cout << "Push number 33 into the mutant stack.\n";
	mStack.push(33);
	std::cout << "Mutant stack size: " << mStack.size() << "\n";

	std::cout << "Push number 42 into the mutant stack.\n";
	mStack.push(42);
	std::cout << "Mutant stack size: " << mStack.size() << "\n";

	std::cout << "All the stack methods: \n";
	std::cout << "top: " << mStack.top() << "\n";

	it = mStack.begin();
	ite = mStack.end();
	std::cout << "Value inside the begin iterator: " <<  *(it) << "\n";
	std::cout << "Value inside the end - 1 iterator: " << *(ite - 1) << "\n";
}
