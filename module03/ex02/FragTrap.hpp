#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &toCopy );
		~FragTrap( void );

		// copy assignment overload
		FragTrap	&operator=( const FragTrap &toAssign );

		void	attack( const std::string& target );
		void	highFivesGuys( void );
};

#endif
