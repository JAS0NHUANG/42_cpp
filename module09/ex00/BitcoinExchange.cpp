#include "BitcoinExchange.hpp"

/*******************************************************************************/
/* validators																   */
/*******************************************************************************/
int		checkArguments(int ac, char **av) {
	if (ac > 2) {
		printError(TOO_MANY_ARGS, "");
		return TOO_MANY_ARGS;
	}
	if (ac < 2 || std::string(av[1]) == "") {
		printError(FILE_ERROR, "");
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
	int		year, month, day, end, feb_days;
	char	dash1, dash2;

	feb_days = 28;
	dateISS >> year >> dash1 >> month >> dash2 >> day >> end;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) {
		if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
			feb_days = 29;
		if (day > feb_days)
			return false;
	}
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
		printError(DATABASE_ERROR, "");
		return DATABASE_ERROR;
	}

	// read db and save data into a std::map
	std::string						line, dateStr, priceStr;
	double							price;

	if (!db_fs.eof())
		getline(db_fs, line);
	while(!db_fs.eof() && getline(db_fs, line)) {
		if (isValidDBLine(line) == false) {
			printError(DATABASE_ERROR, "");
			return DATABASE_ERROR;
		}
		dateStr = line.substr(0, line.find(","));
		priceStr = line.substr(line.find(",") + 1);
		price = atof(priceStr.c_str());

		db_map.insert( std::pair<std::string, double>( dateStr, price ) );
	}
	return 0;
}

std::string	trim(std::string& str) {
	int i = 0;
	int j = (int)str.size() - 1;
	std::string result;
	while (str[i] == ' ')
		i++;
	while (str[j] == ' ')
		j--;
	result = str.substr(i, j + 1);
	return result;
}

int		readInput(std::string& input_str, std::map<std::string, double>& db_map) {
	std::ifstream		input_fs;
	input_fs.open(input_str.c_str());
	if (!input_fs.is_open()) {
		printError(FILE_ERROR, "");
		return FILE_ERROR;
	}

	std::string line;
	std::map<std::string, double>::iterator	map_it;

	// get rid of the first line
	if (!input_fs.eof())
		getline(input_fs, line);
	while (!input_fs.eof() && getline(input_fs, line)) {
		std::string key = line.substr(0, line.find("|"));
		key = trim(key);
		std::string amount_str = line.substr(line.find("|") + 1);
		double		amount = atof(amount_str.c_str());

		if (isValidDate(key) == false) {
			printError(BAD_INPUT, key);
			continue ;
		}
		if (amount < 0) {
			printError(NEGATIVE, "");
			continue ;
		}
		if (amount > 1000) {
			printError(TOO_BIG, "");
			continue ;
		}

		if (db_map.count(key)){
			std::cout << key << " => " << amount << " = " << (amount * db_map[key]) << "\n";
		} else {
			map_it = db_map.upper_bound(key);
			if (map_it == db_map.begin()) {
				printError(NO_BTC, "");
				continue ;
			}
			map_it--;
			std::cout << key << " => " << amount << " = " << (amount * map_it->second) << "\n";
		}

	}
	return 0;
}

/*******************************************************************************/
/* printers																	   */
/*******************************************************************************/

void printError(int statusNumber, std::string err_item) {
	std::string		error_str;
	if (statusNumber == DATABASE_ERROR)
		error_str = "faild reading database.";
	else if (statusNumber == FILE_ERROR)
		error_str = "could not open file.";
	else if (statusNumber == TOO_MANY_ARGS)
		error_str = "too many arguments.";
	else if (statusNumber == NO_BTC)
		error_str = "bitcoin not exist yet.";
	else if (statusNumber == BAD_INPUT)
		error_str = "bad input => ";
	else if (statusNumber == NEGATIVE)
		error_str = "not a positive number.";
	else if (statusNumber == TOO_BIG)
		error_str = "too large a number.";
	std::cout << "Error: " << error_str << err_item << "\n";
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
