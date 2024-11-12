#include "Harl.hpp"

Harl::Harl()
{
	
}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n";
	std::cout << "\n";
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n";
	std::cout << "\n";
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n";
	std::cout << "\n";
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable!\nI want to speak to the manager now.\n";
	std::cout << "\n";
}

void	Harl::complain(std::string level)
{
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	l = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (level == str[i])
		{
			l = i;
			break ;
		}
	}
	switch (l)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break ;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}