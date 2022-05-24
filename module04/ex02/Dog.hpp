#ifndef _DOG_HPP_
# define _DOG_HPP_

# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal {
	public:
		Dog( void );
		Dog( std::string name );
		~Dog( void );
		Dog( const Dog &toCopy );
		Dog	&operator=( const Dog &toAssign);

		// getter
		const std::string	getType( void ) const;

		// member function
		void	makeSound( void ) const;
		void	printIdeas( void ) const;
		void	addIdea(std::string idea);

	private:
		std::string name;
		Brain*	dogBrain;
};

#endif
