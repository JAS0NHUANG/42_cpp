#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &toCopy );
		~ScavTrap( void );

		// copy assignment overload
		ScavTrap	&operator=( const ScavTrap &toAssign );

		// setter
		void	setHP( void );
		void	setEP( void );
		void	setAD( void );

		void	attack(const std::string& target);
		void	guardGate( void );
};

#endif
