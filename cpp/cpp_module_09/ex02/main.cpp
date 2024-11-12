#include "PmergeMe.hpp"

bool IsStrDigit(std::string s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
	try
	{
		if (argc <= 2)
			throw std::logic_error("Wrong format");
		std::vector<int> init_vec;
		std::list<int> init_lst;
		for (int i = 1; i < argc; ++i)
		{
			int n = std::atoi(argv[i]);
			if (n <= 0)
				throw std::logic_error("Non Positive Number error");
			else if (!IsStrDigit(argv[i]))
				throw std::logic_error("Non Number error");
			init_vec.push_back(n);
			init_lst.push_back(n);
		}

		// if (std::is_sorted(init_vec.begin(), init_vec.end()))
		// 	throw std::logic_error("Already sorted");

		std::cout << "Before: ";
		for (size_t i = 0; i < init_vec.size(); ++i)
			std::cout << init_vec[i] << ' ';
		std::cout << '\n';
		std::cout << "After: ";
		clock_t start, finish;
		double duration;
    	PmergeMe pmergeme;
		start = clock();
		std::vector<int> v = pmergeme.MergeInsertSort(init_vec);
		finish = clock();
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << ' ';
		std::cout << '\n';

		std::cout << "Time to process a range of " << v.size() << " elements with std::vector : ";
		duration = static_cast<double>(finish - start) / static_cast<double>(CLOCKS_PER_SEC);
		std::cout << duration << "us\n";

		std::cout << "Before: ";
		for (std::list<int>::iterator it = init_lst.begin(); it != init_lst.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';
		std::cout << "After: ";
		start = clock();
		std::list<int> l = pmergeme.MergeInsertSort(init_lst);
		finish = clock();
		for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';

		std::cout << "Time to process a range of " << l.size() << " elements with std::list : ";
		duration = static_cast<double>(finish - start) / static_cast<double>(CLOCKS_PER_SEC);
		std::cout << duration << "us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

    return 0;
}