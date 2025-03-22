#pragma once

/* ############################################################################################## */

#include <algorithm>
#include <stdexcept>

/* ############################################################################################## */

#define EASYFIND_ERROR	"Value not found in container!"

/* ############################################################################################## */

#include "easyfind.tpp"

/* ############################################################################################## */

template <typename T>	typename T::iterator	   easyfind(T &container, const int value);
template <typename T>	typename T::const_iterator easyfind(const T &container, const int value);