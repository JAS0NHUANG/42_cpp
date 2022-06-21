#include <iostream>
#include <string>
#include <vector>

#include "MutantStack.hpp"


int	main() {
	std::cout << "~~~~~~~ My own tests ~~~~~~~\n";
	{
		std::cout << "~~~~~~~ Int Mutant Stack Tests ~~~~~~~\n";
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
		std::cout << "\n";

		std::cout << "Some inherited stack methods: \n";
		std::cout << "top() (show the top element): " << mStack.top() << "\n";
		std::cout << "empty() (check if the container is empty): " << mStack.empty() << "\n";
		std::cout << "\n";

		std::cout << "Simple iterator tests: \n";
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
		std::cout << "\n";

		std::cout << "Reverse iterator tests: \n";
		MutantStack<int>::reverse_iterator	rIt;	
		MutantStack<int>::reverse_iterator	rIte;	

		rIt = mStack.rbegin();
		rIte = mStack.rend();
		std::cout << "Value inside the rbegin iterator: " <<  *(rIt) << "\n";
		std::cout << "Value inside the rend - 1 iterator: " << *(rIte - 1) << "\n";
		std::cout << "\n";

		std::cout << "~~~~~~~ String Mutant Stack Tests ~~~~~~~\n";

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
		std::cout << "\n";

		std::cout << "Normal iterator tests: \n";
		strIt = mStrStack.begin();
		strIte = mStrStack.end();
		std::cout << "Value inside the begin iterator: " <<  *(strIt) << "\n";
		std::cout << "Value inside the end - 1 iterator: " << *(strIte - 1) << "\n";
		std::cout << "\n";
	}

	std::cout << "~~~~~~~ Tests in the subject ~~~~~~~\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		// this will print out 17 
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		// this will print out 1
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		
		// this will print out 5, 3, 5, 737, 0
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		return 0;
	}
}
