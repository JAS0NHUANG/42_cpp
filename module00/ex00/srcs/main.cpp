#include "megaphone.hpp"

int	main(int ac, char **av) {
	std::string	str_holder;

	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		str_holder = av[i];
		for (int j = 0; j < str_holder.length(); j++)
			std::cout << (char)toupper(str_holder[j]);
	}
	std::cout << '\n';
	return (0);
}
