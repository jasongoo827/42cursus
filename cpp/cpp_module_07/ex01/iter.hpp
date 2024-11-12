#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename R>
void iter(T* arr, size_t len, R (*f))
{
	// std::cout << "normal iter\n";
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);
}

template<typename T, typename R>
void iter(const T* arr, size_t len, R (*f))
{
	// std::cout << "const parameter iter\n";
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);
}

#endif