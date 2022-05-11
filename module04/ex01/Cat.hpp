#ifndef _CAT_HPP_
# define _CAT_HPP_

# include <string>

# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &toCopy );
		Cat	&operator=( const Cat &toAssign);
		Cat( std::string name );

		// member function
		void	makeSound( void ) const;
};

#endif
