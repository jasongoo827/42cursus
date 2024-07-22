#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int>& v)
{
    // pair 로 쪼개기
    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (i == v.size() - 1)
            this->v.push_back(std::make_pair(v[i], -1));
        else
            this->v.push_back(std::make_pair(v[i], v[i + 1]));
    }
}

PmergeMe::PmergeMe(const PmergeMe& other): v(other.v), dq(other.dq)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this == &rhs)
        return (*this);
    v = rhs.v;
    dq = rhs.dq;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    v.clear();
    dq.clear();
}

