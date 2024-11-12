#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap Constructor called!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap Copy Constructor called!\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "DiamondTrap Copy assignment operator called!\n";
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called!\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	// display its name and its ClapTrap name
	std::cout << "My name is " << this->name << ", and ClapTrap name is " << ClapTrap::name << std:: endl;
}

void	DiamondTrap::printTrapInfo()
{
	std::cout << "Name: " << this->name << std:: endl;
	std::cout << "Hit point: " << hitPoint << std:: endl;
	std::cout << "Energy point: " << energyPoint << std:: endl;
	std::cout << "Attack Damage: " << attackDamage << std:: endl;
}