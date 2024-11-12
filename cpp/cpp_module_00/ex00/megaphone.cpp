#include <iostream>
#include <string>
#include <locale>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		std::locale loc;
		for (size_t i = 0; i < str.length(); ++i)
			std::cout << std::toupper(str[i], loc);
	}
	std::cout << std::endl;
	return (0);
}