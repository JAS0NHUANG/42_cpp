#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>

class	ClapTrap {
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		// constructor / destructor
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &toCopy );
		~ClapTrap( void );

		// copy assignment overload
		ClapTrap			&operator=( const ClapTrap &toAssign );

		// getter
		const std::string	&getName( void ) const;
		const int			&getHitPoints( void ) const;
		const int			&getEnergyPoints( void ) const;
		const int			&getAttackDamage( void ) const;

		// member functions
		void				attack( const std::string& target );
		void				takeDamage( unsigned int amount );
		void				beRepaired( unsigned int amount );
};

#endif
