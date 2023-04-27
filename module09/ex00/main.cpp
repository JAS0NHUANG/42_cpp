
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

	printStrDoubleMap(db_map);

	// open and read input file, parse each line and print result
	std::ifstream		input_fs;
	input_fs.open(av[1]);
	if (!input_fs.is_open()) {
		printLine(FILE_ERROR);
		return FILE_ERROR;
	}

/*
	double a = 9.9;
	double b = (int)(a * 100 + .5);
	double c = (double)b/100;
	std::cout << c << "\n";

	std::ostringstream oss;
	oss << c;

	std::cout << std::setprecision(10) << oss.str() << "\n";
*/
	int year, dash;
	std::string str = "1991-ki";
	std::istringstream iss(str);
	if (iss >> year >> dash) {
		std::cout << "year: " << year;
		std::cout << " dash: " << dash;
	}
	std::cout << "year: " << year;
	std::cout << " dash: " << dash;

	return 0;

}
