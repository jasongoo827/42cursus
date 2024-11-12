#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called!\n";
}

ClapTrap::ClapTrap(std::string _name): name(_name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap Constructor called!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap Copy Constructor called!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "ClapTrap Copy assignment operator called\n";
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called!\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoint <= 0 || energyPoint <= 0)
	{
		std::cout << "Cannot do anything!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	energyPoint -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
	if (hitPoint <= amount)
		hitPoint = 0;
	else
		hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint <= 0 || energyPoint <= 0)
	{
		std::cout << "Cannot do anything!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " gets " << amount << " points back!\n";
	hitPoint += amount;
	energyPoint -= 1;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	attackDamage = amount;
}

void	ClapTrap::printTrapInfo(void)
{
	std::cout << "ClapTrap " << name << " Info\n";
	std::cout << "HP: " << hitPoint << '\n';
	std::cout << "EP: " << energyPoint << '\n';
	std::cout << "Attack Damage: " << attackDamage << '\n';
	std::cout << "\n";
}