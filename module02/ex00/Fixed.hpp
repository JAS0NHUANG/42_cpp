class Fixed {
	private:
		int	nbr_value;
		static const int fract_bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &toCopy);
};
