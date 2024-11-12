#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid format\n";
		return (1);
	}
	
	std::string	level(argv[1]);
	Harl	harl;

	harl.complain(level);
}