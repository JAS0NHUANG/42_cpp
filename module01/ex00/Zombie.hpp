#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>
# include <string>

class	Zombie {

	public:
		Zombie( std::string name );
		~Zombie( void );
		void announce( void );

	private:
		std::string	name;
};

Zombie*	newZombie( std::string name );

void	randomChump( std::string name );

#endif
