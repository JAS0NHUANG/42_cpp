#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <iostream>

template <typename T>
int	easyfind(T container, int toFind) {
	typename T::iterator	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("Can't find the number inside the container.");
	return *it;
}

template <typename T>
void	printContainer(T container) {
	typename T::iterator it = container.begin();
	for (int i = 0; i < (int)container.size(); i++) {
		std::cout << *it;
		if (i < (int)container.size() - 1) {
			std::cout << ", ";
		} else {
			std::cout << "\n";
		}
		it++;
	}
}

#endif // EASYFIND_HPP_
