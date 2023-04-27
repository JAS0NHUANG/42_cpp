#include "BitcoinExchange.hpp"

/*******************************************************************************/
/* validators																   */
/*******************************************************************************/
int		checkArguments(int ac, char **av) {
	if (ac > 2) {
		printLine(TOO_MANY_ARGS);
		return TOO_MANY_ARGS;
	}
	if (ac < 2 || std::string(av[1]) == "") {
		printLine(FILE_ERROR);
		return FILE_ERROR;
	}
	return 0;
}
bool	isValidDBLine(std::string line) {
	if (line.find(",") == std::string::npos)
		return false;

	std::string	dateStr, priceStr;
	dateStr = line.substr(0, line.find(","));
	priceStr = line.substr(line.find(",") + 1, line.length());
	if (isValidDate(dateStr) == false)
		return false;
	return true;
}

bool	isValidDate(std::string dateStr) {
	std::istringstream	dateISS(dateStr);
	int		year, month, day, end;
	char	dash1, dash2;

	dateISS >> year >> dash1 >> month >> dash2 >> day >> end;
	if (dash1 == '-' && dash2 == '-' &&
        year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
		return true;
	}
	return false;
}

int		readDB(std::map<std::string, double> & db_map) {
	// open DB
	std::ifstream		db_fs;
	db_fs.open("./files/data.csv");
	if (!db_fs.is_open()) {
		printLine(DATABASE_ERROR);
		return DATABASE_ERROR;
	}

	// read db and save data into a std::map
	std::string						line, dateStr, priceStr;
	double							price;

	if (!db_fs.eof())
		getline(db_fs, line);
	while(!db_fs.eof() && getline(db_fs, line)) {
		if (isValidDBLine(line) == false) {
			printLine(DATABASE_ERROR);
			return DATABASE_ERROR;
		}
		dateStr = line.substr(0, line.find(","));
		priceStr = line.substr(line.find(",") + 1, line.length());
		price = atof(priceStr.c_str());

		db_map.insert( std::pair<std::string, double>( dateStr, price ) );
	}
	return 0;
}

/*******************************************************************************/
/* printers																	   */
/*******************************************************************************/
void	printLine(int statusNumber) {
	if (statusNumber > 0) {
		printError(statusNumber);
		return;
	}
}

void printError(int statusNumber) {
	std::string		error_str;
	if (statusNumber == DATABASE_ERROR)
		error_str = "faild reading database.";
	else if (statusNumber == FILE_ERROR)
		error_str = "could not open file.";
	else if (statusNumber == TOO_MANY_ARGS)
		error_str = "too many arguments.";
	std::cout << "ERROR: " << error_str << "\n";
}


/*******************************************************************************/
/* debug																	   */
/*******************************************************************************/
void	printStrDoubleMap(const std::map<std::string, double> &theMap) {
	std::cout << "\033[1;31m" <<  "Debug: print the Map: \n";

	for (std::map<std::string, double>::const_iterator it = theMap.begin(); it != theMap.end(); it++) {
		std::cout << it->first << ':' << std::setprecision(10) << it->second << "\n";
	}
	std::cout << "\033[0m";
}
