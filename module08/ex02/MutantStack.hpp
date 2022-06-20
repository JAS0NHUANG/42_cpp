#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>
#include <iterator>

template <typename T>
class	MutantStack : public std::stack<T> {

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void) {return (this->c.begin()); }
		iterator	end(void) {return (this->c.end()); }
};

#endif // MUTANTSTACK_HPP_