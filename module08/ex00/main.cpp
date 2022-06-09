#include <vector>
#include <iostream>


int	main() {
	std::vector<int> nbrVector;

	
	for (int i = 0; i < 6; i++) {
		nbrVector.push_back(i);
	}

	nbrVector.push_back(88);

	std::vector<int>::iterator it1 = std::find(nbrVector.begin(), nbrVector.end(), 9);
	std::vector<int>::iterator it2 = std::find(nbrVector.begin(), nbrVector.end(), 10);
	std::vector<int>::iterator it3 = std::find(nbrVector.begin(), nbrVector.end(), 88);

	if (it1 == nbrVector.end()) {
		std::cout << "it1 not found" << "\n";
	} else {
		std::cout << *it1 << "\n";
	}

	if (it2 == nbrVector.end()) {
		std::cout << "it2 not found" << "\n";
	} else {
		std::cout << *it2 << "\n";
	}
	std::cout << *it3 << "\n";
	std::cout << std::distance(nbrVector.begin(), it3) << "\n"; 

	std::vector<int>::iterator itr = nbrVector.begin();
	for (int i = 0; itr + i != nbrVector.end(); i++) {
		std::cout << *(itr + i) << "\n";
	}
	
}
