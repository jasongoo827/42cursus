#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <stdexcept>

class RPN
{
public:
	RPN(std::string& input);
	RPN(const RPN& other);
	RPN& operator=(const RPN& rhs);
	~RPN();

	bool checkValidation(std::string& input);
	void calculate(void);

private:
	std::stack<int> st;
	std::string expression;

	RPN();

};

#endif