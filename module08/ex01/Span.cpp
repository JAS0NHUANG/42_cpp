#include "Span.hpp"

#include <cstddef>
#include <iostream>
#include <numeric>

Span::Span(void) : _n(0) {}

Span::Span(unsigned int N) : _n(N) {
	this->_v.reserve(N);
}

Span::~Span(void) {
	this->_v.clear();
}

Span::Span(Span const & toCopy) {
	*this = toCopy;
}

Span &Span::operator=(Span const & toAssign) {
	this->_n = toAssign._n;
	this->_v.reserve(toAssign._n);
	this->_v.assign(toAssign._v.begin(), toAssign._v.end());
	return (*this);
}

// member functions:
int		Span::size(void) const {
	return (this->_n);
}

void	Span::addNumber(int nbr) {
	if (this->_v.size() == this->_n)
		throw	Span::SpanFullException();
	this->_v.push_back(nbr);
}

int	generator(void) {
	return (0);
}

void	Span::addNumber(void) {
	std::generate_n(this->_v.begin(), (int)this->_n, generator);
	for (unsigned int i = 0; i < this->_n; i++) {
		this->_v.push_back(i);
	}
}

int		Span::getElementByIndex(int index) const {
	return (this->_v[index]);
}

unsigned int	Span::shortestSpan(void) const {
	if (this->size() <= 1)
		throw Span::NotEnoughElementException();

	std::vector<int>	diff(this->size());
	std::vector<int>	sorted(this->_v);
	sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

	return (*std::min_element(diff.begin() + 1, diff.end()));
}

unsigned int	Span::longestSpan(void) const {
	std::vector<int>	sorted(this->_v);
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
