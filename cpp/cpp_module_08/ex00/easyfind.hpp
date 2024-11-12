#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyFind(T& container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("Target not found in container");
	return (it);
}

template <typename T>
typename T::const_iterator easyFind(const T& container, int target)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("Target not found in container");
	return (it);
}

#endif 