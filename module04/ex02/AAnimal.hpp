#ifndef _AANIMAL_HPP_
# define _AANIMAL_HPP_

# include <string>

class	AAnimal {
	public:
		AAnimal( void );
		virtual ~AAnimal( void );
		AAnimal( const AAnimal &toCopy);
		AAnimal	&operator=( const AAnimal &toAssign);

		// getter
		virtual const std::string	getType( void ) const = 0;

		// member functions
		// use virtual for runtime polymorphism
		virtual void	makeSound( void ) const = 0;
		virtual void	printIdeas( void ) const = 0;
		virtual void	addIdea(std::string idea) = 0;

	protected:
		std::string type;
};

#endif
