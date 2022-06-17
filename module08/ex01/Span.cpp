#include "Span.hpp"

Span::Span(void) {
}

Span(unsigned int N) {
	}
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
