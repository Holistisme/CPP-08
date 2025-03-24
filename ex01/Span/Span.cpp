#include "Span.hpp"

Span::Span(const unsigned int size) : _size(size)								   {}
Span::Span(const Span &source)		: _vector(source._vector), _size(source._size) {}

Span &Span::operator=(const Span &source) {
	if (this neq &source) {
		_size	= source._size;
		_vector = source._vector;
	}
	return *this;
}

Span::~Span(void) {}

/* ############################################################################################## */

void Span::addNumber(const int number) {
	_vector.size() neq _size ? _vector.push_back(number)
							 : throw std::logic_error(FULL_VECTOR);
}

/* ############################################################################################## */

size_t Span::shortestSpan(void) const {
	if (_vector.size() lt 2)	throw std::logic_error(EMPTY_VECTOR);

	std::vector<int> sortedVector = _vector;
	std::sort(sortedVector.begin(), sortedVector.end());

	size_t span = std::numeric_limits<size_t>::max();
	for (size_t index = 1; index lt sortedVector.size(); index++) {
		const size_t currentSpan = sortedVector[index] - sortedVector[index - 1];
		if (currentSpan lt span)
			span = currentSpan;
	}
	return span;
}

size_t Span::longestSpan(void) const {
	if (_vector.size() lt 2)	throw std::logic_error(EMPTY_VECTOR);
	
	return *std::max_element(_vector.begin(), _vector.end())
		 - *std::min_element(_vector.begin(), _vector.end());
}

/* ############################################################################################## */

void Span::displayVector(void) const {
	std::ostringstream stream; stream << "Current content in the vector: ";

	if (not _vector.size())
		stream << "none." << std::endl;
	else if (_vector.size() le 42) {
		for (size_t index = 0; index < _vector.size(); index++) {
			stream << _vector[index];
			index + 1 < _vector.size() ? stream << ", "
									   : stream << ".";
		}
	}
	else {
		for (size_t index = 0; index < 21; index++)
			stream << _vector[index] << ", ";
		stream << "[...], ";
		for (size_t index = _vector.size() - 21; index < _vector.size(); index++) {
			stream << _vector[index];
			index + 1 < _vector.size() ? stream << ", "
									   : stream << ".";
		}
	}
	std::cout << stream.str() << std::endl;
}