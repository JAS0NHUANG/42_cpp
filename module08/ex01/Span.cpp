#include "Span.hpp"

#include <cstddef>
#include <iostream>
#include <numeric>

Span::Span(void) : _n(0), _v(new std::vector<int>()) {}

Span::Span(unsigned int N) : _n(N), _v(new std::vector<int>()) {}

Span::~Span(void) {
	delete this->_v;
}

Span::Span(Span const & toCopy) {
	*this = toCopy;
}

Span &Span::operator=(Span const & toAssign) {
	*this = toAssign;
	return (*this);
}

// member functions:
int		Span::size(void) const {
	return (this->_n);
}

void	Span::addNumber(int nbr) {
	if (this->_v->size() == this->_n)
		throw	Span::SpanFullException();
	this->_v->push_back(nbr);
}

int		Span::getElementByIndex(int index) const {
	std::vector<int> *v = this->_v;
	return ((*v)[index]);
}

unsigned int	Span::shortestSpan(void) const {
	if (this->_v->size() <= 1)
		throw Span::NotEnoughElementException();

	std::vector<int>	diff(this->_v->size());
	std::vector<int>	sorted(*(this->_v));
	sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

	return (*std::min_element(diff.begin() + 1, diff.end()));
}

unsigned int	Span::longestSpan(void) const {
	std::vector<int>	sorted(*(this->_v));
	sort(sorted.begin(), sorted.end());

	return (sorted[sorted.size() - 1] - sorted[0]);
}

// exception handling
const char * Span::NotEnoughElementException::what() const throw() {
	return ("Not enouth element.");
}

const char * Span::SpanFullException::what() const throw() {
	return ("The span is full.");
}
