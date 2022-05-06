#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ){
};
ClapTrap::~ClapTrap( std::string name ){};
ClapTrap::ClapTrap( const ClapTrap &toCopy ){};
ClapTrap::ClapTrap	&operator=( const ClapTrap &toAssign ){};

void		ClapTrap::attack( const std::string& target ){};
void		ClapTrap::takeDamage( unsigned int amount ){};
void		ClapTrap::beRepaired( unsigned int amount ){};
