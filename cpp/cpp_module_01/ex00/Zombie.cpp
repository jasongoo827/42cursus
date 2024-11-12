#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string _name): name(_name)
{

}

Zombie::~Zombie()
{
	std::cout << name << " destructed\n";
}

void	Zombie::announce()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}