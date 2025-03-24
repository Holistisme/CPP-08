#pragma once

/* ############################################################################################## */

#include <stack>

/* ############################################################################################## */

#define neq !=

/* ############################################################################################## */

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack &source);
		MutantStack &operator=(const MutantStack &source);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator			   iterator;
		typedef typename std::stack<T>::container_type::const_iterator		   const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	   reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void);
		iterator end(void);

		const_iterator begin(void) const;
		const_iterator end(void)   const;

		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void)   const;
};

/* ############################################################################################## */

#include "MutantStack.tpp"