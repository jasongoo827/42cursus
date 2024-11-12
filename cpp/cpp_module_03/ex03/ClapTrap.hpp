#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	setAttackDamage(unsigned int amount);

protected:
	std::string 	name;
	unsigned int	hitPoint;
	unsigned int	energyPoint;
	unsigned int	attackDamage;

private:
	ClapTrap();
};

#endif