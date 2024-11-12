#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string _type);
	~Weapon();
	
	const std::string&	getType(void);
	void				setType(std::string newType);

private:
	std::string	type;
};

#endif