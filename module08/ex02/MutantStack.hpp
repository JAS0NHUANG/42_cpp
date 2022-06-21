#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>
#include <iterator>

template <typename T>
class	MutantStack : public std::stack<T> {
	public:
		// canonical
		MutantStack(void) {};
		~MutantStack(void) {};
		MutantStack(const MutantStack &toCopy);
		MutantStack	&operator=(const MutantStack &toAssign);

		// typedef
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// iterators
		iterator	begin(void) {return (this->c.begin()); }
		iterator	end(void) {return (this->c.end()); }
		const_iterator	begin(void) const {return (this->c.begin()); }
		const_iterator	end(void) const {return (this->c.end()); }
};

#endif // MUTANTSTACK_HPP_
