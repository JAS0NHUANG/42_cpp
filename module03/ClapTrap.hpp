#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

class	ClapTrap {
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		// canonical form
		ClapTrap( std::string name );
		~ClapTrap( std::string name );
		ClapTrap( const ClapTrap &toCopy );
		ClapTrap	&operator=( const ClapTrap &toAssign );

		// member functions
		void		attack( const std::string& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

#endif
