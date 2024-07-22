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
    if (argc == 2)
    {
        std::cerr << "wront input format\n";
        return 1;
    }

    std::vector<int> init_vec;
    // try - catch 로 수정
    for (int i = 1; i < argc; ++i)
    {
        int n = std::atoi(argv[i]);
        if (n < 0)
        {
            std::cerr << "non positive number error\n";
            return 1;
        }
        else if (!IsStrDigit(argv[i]))
        {
            std::cerr << "non number error\n";
            return 1;
        }
        init_vec.push_back(n);
    }

    // 이미 정렬되어 있을 경우
    if (std::is_sorted(init_vec.begin(), init_vec.end()))
    {
        std::cerr << "already sorted\n";
        return 1;
    }

    PmergeMe pmergeme(init_vec);

    return 0;
}