#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "Test Mutant Stack\n";
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top() = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size() = " << mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "check with iterator\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nCompare with stack - copy constructor\n";
	std::stack<int> s(mstack);
	
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\nCompare with list\n";
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << "lst.front() = " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "lst.size() = " << lst.size() << std::endl;
	std::cout << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "check with iterator\n";
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	return 0;
}