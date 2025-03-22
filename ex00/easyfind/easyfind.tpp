#include "easyfind.hpp"

/* ############################################################################################## */

template <typename T>
typename T::iterator easyfind(T &container, const int value) {
	typename T::iterator dataFound = std::find(container.begin(), container.end(), value);

	if (dataFound == container.end())
		throw std::runtime_error(EASYFIND_ERROR);
	return dataFound;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, const int value) {
	typename T::const_iterator dataFound = std::find(container.begin(), container.end(), value);

	if (dataFound == container.end())
		throw std::runtime_error(EASYFIND_ERROR);
	return dataFound;
}