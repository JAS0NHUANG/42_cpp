#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>
#include <algorithm>

class Span {
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(Span const & toCopy);
		Span &operator=(Span const & toAssign);

		// member functions:
		int		size(void) const;
		void	addNumber(int nbr);
		int		getElementByIndex(int index) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		// exception handling
		class NotEnoughElementException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class SpanFullException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

	private:
		unsigned int	_n;
		std::vector<int> *_v;
};

#endif // SPAN_HPP_
