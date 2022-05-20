#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

# include <iostream>
# include <string>

class	Brain {
	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain &toCopy );
		Brain	&operator=( const Brain &toAssign);

		std::string	ideas[100];
};

#endif
