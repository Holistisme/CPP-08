#pragma once

/* ############################################################################################## */

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <vector>

/* ############################################################################################## */

#define neq !=
#define lt	<
#define le	<=
#define gt	>

#define FULL_VECTOR		 "Class vector filled, impossible to add an element!"
#define NOT_ENOUGH_SPACE "Class almost full, impossible to add all elements!"
#define EMPTY_VECTOR	 "Too few elements to take action!"

/* ############################################################################################## */

class Span {
	public:
		Span(const unsigned int size);
		Span(const Span &source);
		Span &operator=(const Span &source);
		~Span(void);

		void addNumber(const int number);

		template <typename Iter>
		void addNumber(const Iter begin, const Iter end) {
			if (_vector.size() + std::distance(begin, end) gt _size)	throw std::logic_error(NOT_ENOUGH_SPACE);

			for (Iter current = begin; current neq end; current++)
				_vector.push_back(*current);
		}

		size_t shortestSpan(void) const;
		size_t longestSpan(void)  const;

		void displayVector(void) const;
	private:
		std::vector<int> _vector;
		unsigned int	 _size;
};