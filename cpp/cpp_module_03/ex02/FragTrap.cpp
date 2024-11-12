#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name): ClapTrap(_name)
{
	std::cout << "FragTrap Constructor called!\n";
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor called!\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called\n";
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called!\n";
}

void	FragTrap::attack(const std::string target)
{
	if (hitPoint <= 0 || energyPoint <= 0)
	{
		std::cout << "Cannot do anything!\n";
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	energyPoint -= 1;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests high five.\n";
}

void	FragTrap::printTrapInfo(void)
{
	std::cout << "FragTrap " << name << " Info\n";
	std::cout << "HP: " << hitPoint << '\n';
	std::cout << "EP: " << energyPoint << '\n';
	std::cout << "Attack Damage: " << attackDamage << '\n';
	std::cout << "\n";
}