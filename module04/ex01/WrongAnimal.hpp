#ifndef _WRONGANIMAL_HPP_
# define _WRONGANIMAL_HPP_

# include <string>

class	WrongAnimal {
	public:
		WrongAnimal( void );
		~WrongAnimal( void );
		WrongAnimal( const WrongAnimal &toCopy);
		WrongAnimal	&operator=( const WrongAnimal &toAssign);

		// getter
		const std::string	getType( void ) const;

		// member functions
		// withou virtual key word, the makeSound from WrongAnimal will be called
		void	makeSound( void ) const;

	protected:
		std::string type;
};

#endif
