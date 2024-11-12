#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string _name);
	~Zombie();
	
	Zombie	*zombieHorde(int N, std::string name);
	void	announce(void);
	void	setName(std::string _name);

private:
	std::string	name;
};

#endif