#include <vector>
#include <list>

#include "easyfind.hpp"

int	main() {
	std::cout << "~~~~~~~ Test with vector ~~~~~~~\n";
	std::vector<int> nbrVector;
	
	for (int i = 0; i < 6; i++) {
		nbrVector.push_back(i);
	}
	nbrVector.push_back(88);
	printContainer(nbrVector);

	try {
		std::cout << "easyfind: " << easyfind(nbrVector, 9);
		std::cout << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << "easyfind: " << easyfind(nbrVector, 88);
		std::cout << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "~~~~~~~ Test with vector ~~~~~~~\n";
	std::list<int> nbrList;
	
	for (int i = 0; i < 6; i++) {
		nbrList.push_back(i);
	}
	nbrList.push_back(88);
	printContainer(nbrList);

	try {
		std::cout << "easyfind: " << easyfind(nbrList, 9);
		std::cout << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << "easyfind: " << easyfind(nbrList, 88);
		std::cout << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}

	
}
