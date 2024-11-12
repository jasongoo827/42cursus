#include "RPN.hpp"

RPN::RPN(std::string& input)
{
	if (!checkValidation(input))
		throw std::logic_error("Error");
	expression = input;
}

RPN::RPN(const RPN& other): st(other.st), expression(other.expression)
{

}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		return (*this);
	st = rhs.st;
	expression = rhs.expression;
	return (*this);
}

RPN::~RPN()
{

}

bool RPN::checkValidation(std::string& input)
{
	// is digit, +, -, *, /
	int digit = 0;
	int op = 0;

	for (size_t i = 0; i < input.length(); ++i)
	{
		if (isspace(input[i]))
			continue ;
		if (!isdigit(input[i]))
		{
			if (!(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
				return (false);
			op++;
		}
		else
			digit++;
	}
	if (digit - op != 1) return (false);
	return (true);
}

void RPN::calculate(void)
{
	size_t i = -1;

	while (++i < expression.length())
	{
		if (isspace(expression[i]))
			continue ;
		if (isdigit(expression[i]))
			st.push(expression[i] - '0');
		else
		{
			if (st.size() < 2)
				break ;
			int op2 = st.top();
			st.pop();
			int op1 = st.top();
			st.pop();

			int ret;
			if (expression[i] == '+')
				ret = op1 + op2;
			else if (expression[i] == '-')
				ret = op1 - op2;
			else if (expression[i] == '*')
				ret = op1 * op2;
			else if (expression[i] == '/')
			{
				if (op2 == 0)
					throw std::logic_error("Error");
				ret = op1 / op2;
			}
			st.push(ret);
		}
	}
	if (st.size() != 1 || i != expression.length())
		throw std::logic_error("Error");
	std::cout << st.top() << '\n';
}