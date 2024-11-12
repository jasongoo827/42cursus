#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	std::cout << "ScavTrap Constructor called!\n";
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor called!\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "ScavTrap Copy assignment operator called\n";
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called!\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoint <= 0 || energyPoint <= 0)
	{
		std::cout << "Cannot do anything!\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	energyPoint -= 1;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode.\n";
}