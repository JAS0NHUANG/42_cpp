#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( std::string name );
		~FragTrap( void );
		void	highFiveGuys( void );
};

#endif
