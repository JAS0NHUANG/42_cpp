#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	this_is_harl;

	if (ac != 2)
	{
		std::cout << "You should respect the format when complaining.(./harlFileter (complain level))\n";
		return (1);
	}
	std::string	av_str;
	av_str = av[1];

	// Harl's complains
	this_is_harl.complain(av_str);

	return (0);
}
