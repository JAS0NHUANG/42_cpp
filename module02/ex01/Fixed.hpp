#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>

class Fixed {
	private:
		int			value;
		static const int	frctnl_bits;
	public:
		// default constructor
		Fixed(void);

		// constructor overloads
		Fixed(const int number);
		Fixed(const float number);

		// default destructor
		~Fixed(void);

		// copy constructor
		Fixed(const Fixed &toCopy);

		// copy assignment operator overload
		Fixed &operator=(const Fixed &toAssign);

		// getter and setter
		int			getRawBits(void) const;
		void			setRawBits(int const raw);

		// member functions
		float 			toFloat(void) const;
		int 			toInt(void) const;
};

// operator overload. should return a std::ostream reference object
std::ostream &operator<<(std::ostream &out, Fixed const &number);

#endif
