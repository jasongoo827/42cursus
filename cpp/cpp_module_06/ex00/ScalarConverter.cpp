#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string& s)
{
	ValueType type = determineType(s);
	
	if (type == CHAR) printChar(s);
	else if (type == INT) printInt(s);
	else if (type == FLOAT) printFloat(s);
	else if (type == DOUBLE) printDouble(s);
	else printUnknown(s);
}

ValueType determineType(std::string& s)
{
	if (checkChar(s)) return (CHAR);
	else if (checkInt(s)) return (INT);
	else
	{
		ValueType type = checkFloatDouble(s);
		if (type == FLOAT) return (FLOAT);
		else if (type == DOUBLE) return (DOUBLE);
		return (UNKNOWN);
	}
}

void	printChar(std::string& s)
{
	char c = static_cast<char>(s[0]);
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "char: " << c << '\n';
	std::cout << "int: " << static_cast<int>(c) << '\n';
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << '\n';
}

void	printInt(std::string& s)
{
	std::istringstream iss(s);
	int ret;
	iss >> ret;

	std::cout << std::fixed;
	std::cout.precision(1);
	if (!std::isprint(static_cast<char>(ret)))
		std::cout << "char: Non displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(ret) << "\n";
	std::cout << "int: " << ret << '\n';
	std::cout << "float: " << static_cast<float>(ret) << "f\n";
	std::cout << "double: " << static_cast<double>(ret) << "\n";
}

void	printFloat(std::string& s)
{
	std::istringstream iss(s.substr(0, s.find('f')));
	float ret;
	iss >> ret;

	std::cout << std::fixed;
	std::cout.precision(s.length() - s.find('.') - 2);
	if (!std::isprint(static_cast<char>(ret)))
		std::cout << "char: Non displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(ret) << "\n";
	if (static_cast<int>(ret) >= std::numeric_limits<int>::max() || static_cast<int>(ret) <= std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(ret) << '\n';
	std::cout << "float: " << ret << "f\n";
	std::cout << "double: " << static_cast<double>(ret) << '\n';
}

void	printDouble(std::string& s)
{
	std::istringstream iss(s);
	size_t precision = s.find('.') != std::string::npos ? s.find('.') : s.length() - 2;
	if (s.find('.') == s.length() - 1) precision = s.length() - 2;
	double ret;
	iss >> ret;

	std::cout << std::fixed;
	std::cout.precision(s.length() - precision - 1);
	if (!std::isprint(static_cast<char>(ret)))
		std::cout << "char: Non displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(ret) << "\n";
	if (static_cast<int>(ret) >= std::numeric_limits<int>::max() || static_cast<int>(ret) <= std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(ret) << '\n';
	if (static_cast<float>(ret) >= std::numeric_limits<float>::max() || static_cast<float>(ret) <= std::numeric_limits<float>::min())
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << static_cast<float>(ret) << "f\n";
	std::cout << "double: " << ret << '\n';
}

void printUnknown(std::string& s)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf")
	{
		if (s[0] == '-')
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
	}
	else if (s == "inf" || s == "inff")
	{
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	}
	else if (s == "nanf" || s == "nan")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else
	{
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}

bool checkChar(std::string& s)
{
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return (true);
	return (false);
}

bool checkInt(std::string& s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (i == 0 && (s[0] == '-' || s[0] == '+'))
			continue ;
		if (!std::isdigit(s[i]))
			return (false);
	}
	std::istringstream iss(s);
	int ret;
	iss >> ret;
	if (iss.fail())
		return (false);
	return (true);
}

ValueType checkFloatDouble(std::string& s)
{
	bool hasDot = s.find('.') != std::string::npos? true: false;
	bool hasF = s.find('f') == s.length() - 1? true : false;

	if (hasDot && s.find(".", s.find('.') + 1) != std::string::npos) return (UNKNOWN);
	if (!hasF && s.find('f') != std::string::npos) return (UNKNOWN);
	if (hasF && hasDot && s.find('f') - s.find('.') == 1) return (UNKNOWN);
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (i == 0 && (s[0] == '-' || s[0] == '+'))
			continue ;
		if (!std::isdigit(s[i]))
		{
			if (hasDot && s[i] == '.') continue ;
			if (hasF && s[i] == 'f' && i == s.length() - 1) continue ;
			return (UNKNOWN);
		}
	}
	if (!hasDot && hasF) return (UNKNOWN);
	if (hasDot && hasF) return (FLOAT);
	return (DOUBLE);
}
