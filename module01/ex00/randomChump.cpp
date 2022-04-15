#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie zombie_on_the_stack( name );
	zombie_on_the_stack.announce();
	return ;
}
