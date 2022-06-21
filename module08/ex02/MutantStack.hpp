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
		MutantStack(const MutantStack &toCopy) { *this = toCopy; };
		MutantStack	&operator=(const MutantStack &toAssign) {
			if (this == &toAssign) return *this;
			std::stack<T>::operator=(toAssign);
			return *this;
		};

		// typedef
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;


		// iterators
		iterator	begin(void) {return (this->c.begin()); }
		iterator	end(void) {return (this->c.end()); }
		const_iterator	begin(void) const {return (this->c.begin()); }
		const_iterator	end(void) const {return (this->c.end()); }

		// reverse iterators
		reverse_iterator	rbegin(void) {return (this->c.rbegin()); }
		reverse_iterator	rend(void) {return (this->c.rend()); }
		const_reverse_iterator	rbegin(void) const {return (this->c.rbegin()); }
		const_reverse_iterator	rend(void) const {return (this->c.rend()); }

};

#endif // MUTANTSTACK_HPP_
