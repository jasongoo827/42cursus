#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();

	std::vector<int> 							MergeInsertSort(std::vector<int>& v);
	std::list<int> 								MergeInsertSort(std::list<int>& l);
	void										BinaryInsert(std::vector<int>& v, int elem, int low, int high);
	void										BinaryInsert(std::list<int>& l, int elem, int low, int high);
	int 										FindValue(std::vector<std::pair<int, int> >& m, int target);
	int 										FindValue(std::list<std::pair<int, int> >& l, int target);
	std::list<int>::iterator 					GetNthElement(std::list<int>& l, int n);
	std::list<std::pair<int, int> >::iterator 	GetNthElement(std::list<std::pair<int, int> >& l, int n);
	int											Jacobsthal(int n);

private:

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);

};

#endif