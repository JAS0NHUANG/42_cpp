#ifndef _CAT_HPP_
# define _CAT_HPP_

# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {
	public:
		Cat( void );
		Cat( std::string name );
		~Cat( void );
		Cat( const Cat &toCopy );
		Cat	&operator=( const Cat &toAssign);

		// getter
		const std::string	getType( void ) const;

		// member function
		void	makeSound( void ) const;
		void	addIdea( std::string idea);
		void	printIdeas( void ) const;

	private:
		std::string	name;
		Brain* catBrain;
};

#endif
