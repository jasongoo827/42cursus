#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string _name, Weapon& _weapon);
	~HumanA();
	
	void	attack();

private:
	std::string	name;
	Weapon	&weapon;

	HumanA();
};

#endif