#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>

class	ClapTrap {
	private:
		std::string		name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		// canonical form
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap( const ClapTrap &toCopy );
		ClapTrap	&operator=( const ClapTrap &toAssign );
		
		// getter / setter
		void	setName( std::string &name );
		void	setHitPoints( int hitPoints);
		void	setEnergyPoints( int energyPoints );
		void	setAttackDamage( int attackDamage );

		const std::string	&getName( void ) const;
		const int		&getHitPoints( void ) const;
		const int		&getEnergyPoints( void ) const;
		const int		&getAttackDamage( void ) const;

		// member functions
		void		attack( const std::string& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

#endif
