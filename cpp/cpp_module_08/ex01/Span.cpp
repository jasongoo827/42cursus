#include "Span.hpp"

Span::Span(unsigned int N): size(N)
{

}

Span::Span(const Span& other): mySet(other.mySet), size(other.size)
{

}

Span& Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return (*this);
	mySet = rhs.mySet;
	size = rhs.size;
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber(int num)
{
	if (mySet.size() >= size)
		throw std::out_of_range("Span is full!");
	mySet.insert(num);
}

int Span::shortestSpan(void)
{
	if (mySet.size() < 2)
		throw NoSpanException();
	
	int shortestSpan = std::numeric_limits<int>::max();
	std::set<int>::iterator next_it = ++mySet.begin();
	for (std::set<int>::iterator it = mySet.begin(); next_it != mySet.end(); ++it)
	{
		int span = *next_it - *it;
		if (span < shortestSpan)
			shortestSpan = span;
		++next_it;
	}
	return (shortestSpan);
}

int Span::longestSpan(void)
{
	if (mySet.size() < 2)
		throw NoSpanException();
	std::set<int>::iterator endIt = mySet.end();
	return (*(--endIt) - *mySet.begin());
}
