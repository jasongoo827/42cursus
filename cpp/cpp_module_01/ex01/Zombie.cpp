#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string _name): name(_name)
{

}

void	Zombie::setName(std::string _name)
{
	name =  _name;
}


void	Zombie::announce()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << name << " destructed\n";
}