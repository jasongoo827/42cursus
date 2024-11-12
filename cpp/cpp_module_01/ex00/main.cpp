#include "Zombie.hpp"

int main(void)
{
	std::string name = "Foo";

	Zombie	z("Z");
	Zombie* zombie = z.newZombie(name);
	zombie->announce();
	delete zombie;

	std::string other_name = "jgoo";
	z.randomChump(other_name);
}