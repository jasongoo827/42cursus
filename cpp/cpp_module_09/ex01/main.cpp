#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error\n";
		return 1;
	}
	try
	{
		std::string input(argv[1]);
		RPN rpn(input);
		rpn.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;	
}