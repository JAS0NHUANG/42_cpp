#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <string>

class	Animal {
	public:
		Animal( void );
		virtual ~Animal( void );
		Animal( const Animal &toCopy);
		Animal	&operator=( const Animal &toAssign);

		// getter
		const std::string	getType( void ) const;

		// member functions
		// use virtual for runtime polymorphism
		virtual void	makeSound( void ) const;
		virtual void	printIdeas( void ) const;
		virtual void	addIdea(std::string idea);

	protected:
		std::string type;
};

#endif
