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
	void		(Harl::*ft_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0)
			(this->*ft_ptr[i])();
	}
	return ;
};
