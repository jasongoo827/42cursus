#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::MergeInsertSort(std::vector<int>& v)
{
	size_t n = v.size();
	if (n == 1)
		return v;
	std::vector<int> a, b;
	for (size_t i = 0; i < (n / 2); ++i)
	{
		if (v[2 * i] > v[2 * i + 1])
		{
			a.push_back(v[2 * i]);
			b.push_back(v[2 * i + 1]);
		}
		else
		{
			a.push_back(v[2 * i + 1]);
			b.push_back(v[2 * i]);
		}
	}
	if (n % 2 == 1)
		b.push_back(v[n - 1]);

	std::vector<std::pair<int, int> > m;
	for (size_t i = 0; i < (n / 2); ++i)
		m.push_back(std::make_pair(a[i], b[i]));
	a = MergeInsertSort(a);
	for (size_t i = 0; i < (n / 2); ++i)
		b[i] = FindValue(m, a[i]);

	std::vector<int> sorted;
	sorted.push_back(b[0]);
	for (size_t i = 0; i < a.size(); ++i)
		sorted.push_back(a[i]);

	size_t k = 2;
	size_t tk = 1, tk_prev = 1;
	size_t num = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
	while (tk_prev < num)
	{
		size_t m = std::min(tk, num);
		size_t u = tk_prev + m - 1;
		for (size_t i = m - 1; i >= tk_prev; i--)
		{
			BinaryInsert(sorted, b[i], 0, u);
			while (sorted[u] != a[i - 1])
				u--;
		}
		++k;
		tk_prev = tk;
		tk = 2 * k - 1;
	}
	return sorted;
}

std::list<int> PmergeMe::MergeInsertSort(std::list<int>& l)
{
	size_t n = l.size();

	if (n == 1)
		return l;
	std::list<int> a, b;
	for (size_t i = 0; i < (n / 2); ++i)
	{
		std::list<int>::iterator i1 = GetNthElement(l, 2 * i);
		std::list<int>::iterator i2 = GetNthElement(l, 2 * i + 1);
		if (*i1 > *i2)
		{
			a.push_back(*i1);
			b.push_back(*i2);
		}
		else
		{
			a.push_back(*i2);
			b.push_back(*i1);
		}
	}
	if (n % 2 == 1)
		b.push_back(*GetNthElement(l, n - 1));

	std::list<std::pair<int, int> > m;
	for (size_t i = 0; i < (n / 2); ++i)
		m.push_back(std::make_pair(*GetNthElement(a, i), *GetNthElement(b, i)));
	a = MergeInsertSort(a);
	for (size_t i = 0; i < (n / 2); ++i)
		*GetNthElement(b, i) = FindValue(m, *GetNthElement(a, i));

	std::list<int> sorted;
	sorted.push_back(*GetNthElement(b, 0));
	for (size_t i = 0; i < a.size(); ++i)
		sorted.push_back(*GetNthElement(a, i));

	size_t k = 1;
	size_t tk = Jacobsthal(1), tk_prev = Jacobsthal(0);
	// size_t k = 2;
	// size_t tk = 1, tk_prev = 1;
	size_t num = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
	while (tk_prev < num)
	{
		size_t m = std::min(tk, num);
		size_t u = tk_prev + m - 1;
		for (size_t i = m - 1; i >= tk_prev; i--)
		{
			BinaryInsert(sorted, *GetNthElement(b, i), 0, u);
			while (*GetNthElement(sorted, u) != *GetNthElement(a, i - 1))
				u--;
		}
		++k;
		tk_prev = tk;
		tk = Jacobsthal(k);
		// tk = 2 * k - 1;
	}
	return sorted;
}

void PmergeMe::BinaryInsert(std::vector<int>& v, int element, int low, int high)
{
	// std::cout << "Binary Insertion elem: " << element << " low : " << low << " high: " << high << '\n';
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (v[mid] < element)
			low = mid + 1;
		else
			high = mid;
    }
	v.insert(v.begin() + low, element);
}

void PmergeMe::BinaryInsert(std::list<int>& l, int element, int low, int high)
{
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (*GetNthElement(l, mid) < element)
			low = mid + 1;
		else
			high = mid;
    }
	l.insert(GetNthElement(l, low), element);
}

int PmergeMe::FindValue(std::vector<std::pair<int, int> >& m, int target)
{
	for (size_t i = 0; i < m.size(); ++i)
	{
		if (m[i].first == target)
		{
			m[i].first = 0;
			return m[i].second;
		}
	}
	throw std::out_of_range("out of range");
}

int PmergeMe::FindValue(std::list<std::pair<int, int> >& l, int target)
{
	for (size_t i = 0; i < l.size(); ++i)
	{
		std::list<std::pair<int, int> >::iterator it = GetNthElement(l, i);
		if (it->first == target)
		{
			it->first = 0;
			return it->second;
		}
	}
	throw std::out_of_range("out of range");
}

std::list<int>::iterator PmergeMe::GetNthElement(std::list<int>& l, int n)
{
    if (n < 0 || n > static_cast<int>(l.size()))
        throw std::out_of_range("index is out of range");
    std::list<int>::iterator it = l.begin();
    std::advance(it, n);
    return it;
}

std::list<std::pair<int, int> >::iterator PmergeMe::GetNthElement(std::list<std::pair<int, int> >& l, int n)
{
    if (n < 0 || n > static_cast<int>(l.size()))
        throw std::out_of_range("index is out of range");
    std::list<std::pair<int, int> >::iterator it = l.begin();
    std::advance(it, n);
    return it;
}

int	PmergeMe::Jacobsthal(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int a = 1, b = 1, c;
	for (int i = 2; i <=n; ++i)
	{
		c = b + 2 * a;
		b = c;
		a = b;
	}
	return c;
}
