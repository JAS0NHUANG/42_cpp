#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed {

	private:
		int			value;
		static const int	frctnl_bits;

	public:
		// default constructor
		Fixed( void );
		
		// copy constructor
		Fixed(const Fixed &toCopy);

		// default destructor
		~Fixed( void );

		// copy assignment operator overload
		Fixed &operator=( const Fixed &toAssign );

		// getter/setter
		int			getRawBits( void ) const;
		void			setRawBits( int const raw );
};

#endif
