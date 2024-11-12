#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <deque>
#include <exception>
#include <algorithm>

class BitcoinExchange
{
public:
	BitcoinExchange(std::string& csv);
	~BitcoinExchange();

	static std::string 						InputToString(std::ifstream& infile);
	bool									CheckFormat(std::string& line);
	bool									CheckFirstLine(std::string& line);
	bool									CheckDateFormat(std::string& date);
	bool									CheckValue(std::string& value);
	bool									CheckLeapYear(int year);
	static bool								IsStrSpace(std::string& s);

	const std::map<std::string, float>& 	GetMap();

private:
	std::map<std::string, float> m;

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
};

#endif