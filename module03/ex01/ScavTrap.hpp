#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &toCopy );
		~ScavTrap( void );

		// copy assignment overload
		ScavTrap	&operator=( const ScavTrap &toAssign );

		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif
