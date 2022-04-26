#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed {
	private:
		int			value;
		static const int	frctnl_bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		// copy constructor
		Fixed(const Fixed &toCopy);
		// copy assignment operator overload
		Fixed &Fixed::operator=(const Fixed &toAssign);

		int			getRawBits(void) const;
		void			setRawBits(int const raw);
};

#endif
