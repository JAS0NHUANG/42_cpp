#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>

class	ClapTrap {
	private:
		std::string	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public:
		// constructor / destructor
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &toCopy );
		~ClapTrap( void );

		ClapTrap	&operator=( const ClapTrap &toAssign );

		// getter
		const std::string	&getName( void ) const;
		const unsigned int	&getHitPoints( void ) const;
		const unsigned int	&getEnergyPoints( void ) const;
		const unsigned int	&getAttackDamage( void ) const;

		// member functions
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
