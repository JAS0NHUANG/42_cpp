
#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	int	returnValue = 0;

	/*******************************************************************************/
	/* check arguments															   */
	/*******************************************************************************/
	if ((returnValue = checkArguments(ac, av)) > 0)
		return returnValue;

	// open db file
	std::map<std::string, double>	db_map;
	if ((returnValue = readDB(db_map)) > 0)
		return returnValue;

	/*******************************************************************************/
	// debug
	/*******************************************************************************/
	// printStrDoubleMap(db_map);

	/*******************************************************************************/
	// open and read input file, parse each line and print result
	/*******************************************************************************/
	std::string input_str = std::string(av[1]);

	readInput(input_str, db_map);

/*
	int year, dash;
	std::string str = "1991-ki";
	std::istringstream iss(str);
	if (iss >> year >> dash) {
		std::cout << "year: " << year;
		std::cout << " dash: " << dash;
	}
	std::cout << "year: " << year;
	std::cout << " dash: " << dash;
	*/

	return 0;

}
