#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <limits>
#include <exception>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& rhs);
	~Span();

	void 	addNumber(int num);
	int		shortestSpan(void);
	int 	longestSpan(void);

	template <typename T>
	void	fill(T first, T last)
	{
		if (std::distance(first, last) + mySet.size() > size)
			throw std::out_of_range("Span is full!");
		while (first != last)
		{
			mySet.insert(static_cast<int>(*first));
			++first;
		}
	}
	
private:
	class NoSpanException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "No Span can be found";
		}
	};
	std::set<int> mySet;
	unsigned int size;

	Span();
};

#endif