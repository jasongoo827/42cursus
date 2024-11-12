#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string& csv)
{
	std::istringstream iss(csv);
	std::string str;
	int cnt = 0;
	while (getline(iss, str, '\n'))
	{
		if (str.empty() || IsStrSpace(str))
			continue ;
		if (cnt == 0 && !CheckFirstLine(str))
			throw std::logic_error("Wrong first line format");
		else if (cnt != 0 && !CheckFormat(str))
			throw std::logic_error("Wrong line format");
		++cnt;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	m.clear();
}

std::string BitcoinExchange::InputToString(std::ifstream& infile)
{
	infile.seekg(0, std::ios::end);
	size_t size = infile.tellg();
	infile.seekg(0, std::ios::beg);
	
	char *buffer = new char[size];
	if (!infile.read(buffer, size))
	{
		std::cerr << "cannot read\n";
		infile.close();
		delete []buffer;
		throw ;
	}
	infile.close();
	std::string csv(buffer, size);
	delete []buffer;

	return (csv);
}

bool BitcoinExchange::CheckFormat(std::string& line)
{
	std::istringstream iss(line);
	std::string str;
	std::deque<std::string> dq;
	char *end;

	while (getline(iss, str, ','))
		dq.push_back(str);
	if (dq.size() != 2)
		return false;
	if (str.find(',') != str.rfind(','))
		return false;
	if (!CheckDateFormat(dq.front()))
		return false;
	if (!CheckValue(dq.back()))
		return false;
	m.insert(std::make_pair(dq.front(), std::strtof(dq.back().c_str(), &end)));
	return true;
}

bool BitcoinExchange::CheckFirstLine(std::string& line)
{
	std::istringstream iss(line);
	std::string str;
	std::deque<std::string> dq;

	while (getline(iss, str, ','))
		dq.push_back(str);
	if (dq.size() != 2)
		return false;
	if (str.find(',') != str.rfind(','))
		return false;
	if (dq.front() != "date" || dq.back() != "exchange_rate")
		return false;
	return true;
}

bool BitcoinExchange::CheckDateFormat(std::string& date)
{
	std::istringstream iss(date);
	std::string str;
	std::deque<std::string> dq;
	int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while (getline(iss, str, '-'))
		dq.push_back(str);
	if (dq.size() != 3)
		return false;
	// - 개수 체크

	int year = std::atoi(dq[0].c_str());
	if (year < 2009)
		return false;

	int month = std::atoi(dq[1].c_str());
	if (month < 1 || month > 12)
		return false;

	int day = std::atoi(dq[2].c_str());
	if (month == 2 && CheckLeapYear(year))
	{
		if (day <= 0 || day > 29)
			return false;
	}
	else if (day <= 0 || day > d[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::CheckValue(std::string& value)
{
	// value 확인 - float or positive integer, between 0 and 1000
	char *end;
	float v = std::strtof(value.c_str(), &end);
	if (end != value.c_str() && *end != '\0')
		return false;
	if (v < 0)
		return false;
	return true;
}

bool BitcoinExchange::CheckLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
			return true;
	}
	return false;
}

const std::map<std::string, float>& BitcoinExchange::GetMap()
{
	return m;
}

bool BitcoinExchange::IsStrSpace(std::string& s)
{
	for (size_t i = 0; i < s.length(); ++i)
		if (!isspace(s[i]))
			return false;
	return true;
}