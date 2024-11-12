#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& rhs);
	T& operator[](int index) const;
	~Array();

	unsigned int size() const;

private:
	T* arr;
	unsigned int arr_size;

};

template <typename T>
Array<T>::Array(): arr(new T()), arr_size(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]), arr_size(n)
{
	for (unsigned int i = 0; i < arr_size; ++i)
		arr[i] = T();
}

template <typename T>
Array<T>::Array(const Array& other): arr(new T[other.size()]), arr_size(other.size())
{
	for (unsigned int i = 0; i < arr_size; ++i)
		arr[i] = other[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return (*this);
	delete arr;
	arr_size = rhs.size();
	arr = new T[rhs.size()];
	for (unsigned int i = 0; i < arr_size; ++i)
		arr[i] = rhs[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) > arr_size)
		throw std::exception();
	return (arr[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (arr_size);
}

#endif