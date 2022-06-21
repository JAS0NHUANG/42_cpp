#include <iostream>
#include <string>
#include <vector>

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

	std::cout << "Normal iterator tests: \n";
	it = mStack.begin();
	ite = mStack.end();
	std::cout << "Value inside the begin iterator: " <<  *(it) << "\n";
	std::cout << "Value inside the end - 1 iterator: " << *(ite - 1) << "\n";

	while (it != ite) {
		int	value = *(it);
		std::cout << value << "\n";
		*(it) = value + 1;
		it++;
	}
	it = mStack.begin();
	std::cout << "Value inside the begin iterator: " <<  *(it) << "\n";
	std::cout << "Value inside the end - 1 iterator: " << *(ite - 1) << "\n";

	std::cout << "\n";
	std::cout << "Const iterator tests: \n";
	MutantStack<int>::const_iterator	const_it;	
	MutantStack<int>::const_iterator	const_ite;	

	const_it = mStack.begin();
	const_ite = mStack.end();
	std::cout << "Value inside the begin const iterator: " <<  *(const_it) << "\n";
	std::cout << "Value inside the end - 1 const iterator: " << *(const_ite - 1) << "\n";
	/* Can not modify values by const_iterator. This part won't compile.
	while (const_it != const_ite) {
		int	value = *(const_it);
		std::cout << value << "\n";
		*(const_it) = value + 1;
		const_it++;
	}
	it = mStack.begin();
	std::cout << "Value inside the begin iterator: " <<  *(it) << "\n";
	std::cout << "Value inside the end - 1 iterator: " << *(ite - 1) << "\n";
	*/

	MutantStack<std::string> mStrStack;
	MutantStack<std::string>::iterator	strIt;	
	MutantStack<std::string>::iterator	strIte;	

	std::cout << "Push string hello into the mutant stack.\n";
	mStrStack.push("hello");

	std::cout << "Push string world into the mutant stack.\n";
	mStrStack.push("world");

	std::cout << "Push string 42 into the mutant stack.\n";
	mStrStack.push("42");
	std::cout << "Mutant stack size: " << mStrStack.size() << "\n";

	std::cout << "All the stack methods: \n";
	std::cout << "top: " << mStrStack.top() << "\n";

	std::cout << "Normal iterator tests: \n";
	strIt = mStrStack.begin();
	strIte = mStrStack.end();
	std::cout << "Value inside the begin iterator: " <<  *(strIt) << "\n";
	std::cout << "Value inside the end - 1 iterator: " << *(strIte - 1) << "\n";
 

	std::vector<int> intV;

	std::vector<int>::iterator vecIt;
	vecIt = intV.begin();
	std::cout << *vecIt;
}
