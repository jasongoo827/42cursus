#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string _name);
	~Zombie();

	Zombie	*newZombie(std::string name);
	void	announce(void);
	void	randomChump(std::string name);
	
private:
	std::string	name;
};

#endif