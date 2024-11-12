#include "easyfind.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	// vector
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	// list
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(int));
	// deque
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		std::cout << "Vector Container test - when find success\n";
		std::vector<int>::iterator it = easyFind(v, 3);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nVector Container test - when find fail\n";
		std::vector<int>::iterator it = easyFind(v, 6);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nVector Container test - when find success\n";
		std::vector<int>::iterator it = easyFind(v, 3);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nVector Container const_iterator test - when find success\n";
		std::vector<int>::const_iterator it = easyFind(v, 5);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nList Container test - when find fail\n";
		std::list<int>::iterator it = easyFind(l, 6);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nDeque Container test - when find success\n";
		std::deque<int>::iterator it = easyFind(dq, 3);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nDeque Container test - when find fail\n";
		std::deque<int>::iterator it = easyFind(dq, 6);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nConst Deque Container test - when find success\n";
		const std::deque<int> dq2(arr, arr + sizeof(arr) / sizeof(int));
		
		std::deque<int>::const_iterator it = easyFind(dq2, 4);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}