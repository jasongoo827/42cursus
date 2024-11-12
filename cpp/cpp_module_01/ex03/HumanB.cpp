#include "HumanB.hpp"

HumanB::HumanB(std::string _name): name(_name), weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	if (weapon == NULL)
	{
		std::cout << name << " has no weapon\n";
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	weapon = &_weapon;
}