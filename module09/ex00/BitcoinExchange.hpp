#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <stdlib.h>
# include <iomanip>

enum eStatusCode {
	DATABASE_ERROR = 1,
	FILE_ERROR,
	TOO_MANY_ARGS,
	BAD_INPUT,
	NEGATIVE,
	TOO_BIG,
};

// validators
int				checkArguments(int ac, char **av);
bool			isValidDBLine(std::string line);
bool			isValidInput(std::string line);
bool			isValidDate(std::string dateStr);
bool			isValidPrice(std::string);
bool			isNumber(std::string numberStr);
bool			isNegativeNumber(double);
bool			isNumberInRange(double);

// utils
int				readDB(std::map<std::string, double> & db_map);
std::string		trim(std::string str);

// printer
void			printLine(int statusNumber);
void			printError(int errorNumber);

void			printStrDoubleMap(const std::map<std::string, double> &theMap);

#endif
