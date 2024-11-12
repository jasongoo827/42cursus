#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// container_type c
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_iterator cbegin() { return this->c.cbegin(); }
	const_iterator cend() { return this->c.cend(); }
	const_reverse_iterator crbegin() { return this->c.crbegin(); }
	const_reverse_iterator crend() { return this->c.crend(); }
};

#endif