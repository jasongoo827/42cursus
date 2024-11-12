#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(std::string _name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();

	void	attack(const std::string target);
	void	highFivesGuys(void);
	
private:
	FragTrap();

};

#endif