#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		~ScavTrap( void );
		void	guardGate( void );
};

#endif
