#ifndef SPAN_HPP_
#define SPAN_HPP_

class Span {
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(Span const & toCopy);
		Span &operator=(Span const & toAssign);

		// member functions:
		void	addnumber(int nbr);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		// exception handling
		class NotEnoughElementException : public std::exception {
			public:
				const & std::exception::what() const throw();
		}


	private:
		unsigned int	_n;
		unsigned int	_count;
		std::vector<int> *_v;
};

#endif // SPAN_HPP_
