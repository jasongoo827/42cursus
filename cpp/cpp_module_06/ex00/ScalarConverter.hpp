#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter
{
public:
	static void convert(std::string& s);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();
};

enum ValueType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

ValueType 	determineType(std::string& s);
bool 		checkChar(std::string& s);
bool		checkInt(std::string& s);
ValueType 	checkFloatDouble(std::string& s);

void		printChar(std::string& s);
void		printInt(std::string& s);
void		printFloat(std::string& s);
void		printDouble(std::string& s);
void		printUnknown(std::string& s);

#endif