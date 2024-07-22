#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>
#include <exception>

class PmergeMe
{
public:
    PmergeMe(std::vector<int>& v);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();


private:
    std::vector<std::pair<int, int> >   v;
    std::vector<int>                    sorted_vec;
    std::deque<std::pair<int, int> >    dq;
    std::deque<int>                     sorted_dq;

};

#endif