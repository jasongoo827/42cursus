#include "BitcoinExchange.hpp"

bool CheckFirstLine(std::string& line)
{
	std::istringstream iss(line);
	std::string str;
	std::deque<std::string> dq;

	while (getline(iss, str, '|'))
		dq.push_back(str);
	if (dq.size() != 2)
		return false;
	if (str.find('|') != str.rfind('|'))
		return false;
	if (dq.front() != "date " || dq.back() != " value")
		return false;
	return true;
}

bool CheckValue(std::string& value)
{
	// value 확인 - float or positive integer, between 0 and 1000
	char *end;
	float v = std::strtof(value.c_str(), &end);
	if (end != value.c_str() && *end != '\0')
	{
		std::cout << "Error: wrong format value.\n";
		return false;
	}
	if (v < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (v > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}

bool CompareYear(const std::string& d1, const std::string& d2)
{
	size_t p1 = 0;
	size_t p2 = 0;
	for (size_t i = 0; i < d1.length(); ++i)
	{
		if (d1[i] == '-')
			break ;
		p1++;
	}
	for (size_t i = 0; i < d2.length(); ++i)
	{
		if (d2[i] == '-')
			break ;
		p2++;
	}
	if (d1.substr(0, p1) != d2.substr(0, p2))
		return false;
	return true;
}

void GetValue(std::string& line, BitcoinExchange& ex)
{
	std::istringstream iss(line);
	std::string str;
	std::deque<std::string> dq;

	while (getline(iss, str, '|'))
		dq.push_back(str);
	if (dq.size() != 2)
	{
		if (dq.size() == 1)
			std::cout << "Error: bad input => " << dq.front() << '\n';
		else
			std::cout << "Error: bad input\n";
		return ;
	}
	if (!ex.CheckDateFormat(dq.front()))
	{
		std::cout << "Error: bad input => " << dq.front() << '\n';
		return ;
	}
	if (!CheckValue(dq.back()))
		return ;

	char *end;
	std::string date = dq.front();
	date.resize(date.length() - 1);
	float value = std::strtof(dq.back().c_str(), &end);
	std::map<std::string, float> map = ex.GetMap();
	if (map.find(date) != map.end())
	{
		std::cout << date << " => " << value << " = " << map[date] * value << '\n';
	}
	else
	{
		// 날짜 가장 가까운 녀석을 가져온다.
		std::map<std::string, float>::iterator it = map.lower_bound(date);
		if (it == map.begin())
		{
			std::cout << "Error: date doesn't exist.\n";
			return ;
		}
		else if (it == map.end())
		{
			std::map<std::string, float>::iterator it2 = map.end();
			it2--;
			if (!CompareYear(date, it2->first))
			{
				std::cout << "Error: Too far date.\n";
				return ;
			}
			else
				it--;
		}
		else
			it--;
		std::cout << date << " => " << value << " = " << it->second * value << '\n';
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	try
	{
		std::ifstream file("data.csv", std::ios::in);
		if (!file)
			throw std::logic_error("Error: could not open file.\n");
		std::string csv = ::BitcoinExchange::InputToString(file);
		BitcoinExchange ex(csv);

		std::ifstream infile(argv[1], std::ios::in);
		if (!infile)
			throw std::logic_error("Error: could not open file.\n");
		std::string input = ::BitcoinExchange::InputToString(infile);

		std::istringstream iss(input);
		std::string str;
		int cnt = 0;
		while (getline(iss, str, '\n'))
		{
			if (str.empty() || ::BitcoinExchange::IsStrSpace(str))
				continue ;
			if (cnt == 0 && !CheckFirstLine(str))
				throw std::logic_error("Error: wrong format value.\n");
			else if (cnt != 0)
				GetValue(str, ex);
			++cnt;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}