#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	~DiamondTrap();

	void	attack(const std::string &target);
	void	whoAmI();
	void	printTrapInfo();

private:
	std::string	name;

	DiamondTrap();
};

#endif