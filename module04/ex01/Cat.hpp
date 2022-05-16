#ifndef _CAT_HPP_
# define _CAT_HPP_

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
	public:
		Cat( void );
		Cat( std::string name );
		~Cat( void );
		Cat( const Cat &toCopy );
		Cat	&operator=( const Cat &toAssign);

		// member function
		void	makeSound( void ) const;

	private:
		std::string	name;
		Brain* catBrain;
};

#endif
