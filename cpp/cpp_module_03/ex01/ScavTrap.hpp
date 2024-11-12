#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate(void);
	void	printTrapInfo(void);
	
private:
	ScavTrap();
	
};

#endif