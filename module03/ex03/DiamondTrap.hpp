#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	name;

	public:
		// constructor / destructor
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &toCopy );
		~DiamondTrap( void );

		// member functions
		using				ScavTrap::attack;
		void				whoAmI( void ) const;
		const std::string	&getName( void ) const;
};
