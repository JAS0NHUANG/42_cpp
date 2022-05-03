#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed {

	private:
		int			value;
		static const int	frctnl_bits;

	public:
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	constructor & destructor                                          */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Fixed( void );
		Fixed( const Fixed &toCopy );
		Fixed( const int number );
		Fixed( const float number );
		~Fixed( void );

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	copy assignment operator overload								  */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Fixed	&operator=( const Fixed &toAssign );

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	getter / setter						                              */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	member functions				                                  */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	comparison operators: >, <, >=, <=, ==, != 			              */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		bool	operator>( const Fixed &right ) const;
		bool	operator<( const Fixed &right ) const;
		bool	operator>=( const Fixed &right ) const;
		bool	operator<=( const Fixed &right ) const;
		bool	operator==( const Fixed &right ) const;
		bool	operator!=( const Fixed &right ) const;

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*	arithmetic operators: +, -, *, /        			              */
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Fixed	operator+( const Fixed &right) const;
		Fixed	operator-( const Fixed &right) const;
		Fixed	operator*( const Fixed &right) const;
		Fixed	operator/( const Fixed &right) const;
};

// insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &number);

#endif
