#include "Harl.hpp"

Harl::Harl( void ){};

Harl::~Harl( void ){};


void	Harl::debug( void ){
	std::cout << "This is debug level complain. Not using the example comments~~~!!!!!\n";
	return ;
};

void	Harl::info( void ){
	std::cout << "Info level complain. No example coments~~~!!!!!\n";
	return ;
};

void	Harl::warning( void ){
	std::cout << "I'm WARNING you~~~ NO EXAMPLE COMENTS~~~~!!!!!!!\n";
	return ;
};

void	Harl::error( void ){
	std::cout << "ERROR ERROR ERROR ERROR ERROR ERROR~~~~~~!!!!!!\n";
	return ;
};

void	Harl::complain( std::string level ){
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level_nbr = -1;

	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0)
			level_nbr = i;
	}

	switch (level_nbr) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			this->debug();
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]\n";
			this->info();
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			this->warning();
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			this->error();
			std::cout << "\n";
			break ;
		default:
			std::cout << "[ MUUUUUURRRRRRRR MUUUUUUURRRRRRR~~~~~~ ]\n";
			break ;
	}
	return ;
};
