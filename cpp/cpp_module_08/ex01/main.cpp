#include "Span.hpp"
#include <vector>
#include <list>

 int main(void)
 {
	{
		std::cout << "BASIC TEST\n";
		Span sp = Span(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;

		try
		{
			std::cout << "\nCHECK ADD NUMBER EXCEPTION\n";
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\nFILL BY VECTOR\n";

		Span sp = Span(5);

		int arr[5] = {18, 2 , 5, 23, 8};
		std::vector<int> v(arr, arr + (sizeof(arr) / sizeof(int)));
		sp.fill(v.begin(), v.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;

		try
		{
			std::cout << "\nCHECK FILL EXCEPTION\n";
			sp.fill(v.begin(), v.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\nFILL BY VECTOR + ADD NUMBER\n";

		Span sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		int arr[5] = {18, 2 , 5, 23, 8};
		std::vector<int> v(arr, arr + (sizeof(arr) / sizeof(int)));
		sp.fill(v.begin(), v.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nFILL BY LIST\n";

		Span sp = Span(100000);

		std::list<int> l;
		for (int i = 0; i < 100000; ++i)
			l.push_back(i + 1);
		sp.fill(l.begin(), l.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
 }