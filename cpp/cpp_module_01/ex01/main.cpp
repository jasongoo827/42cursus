#include "Zombie.hpp"

// void check_leak(void)
// {
// 	system("leaks ex01");
// }

int main(void)
{
	// atexit(check_leak);
	Zombie	z("Z");
	Zombie	*zombieHorde = z.zombieHorde(10, "zzzoombiee");

	for (int i = 0; i < 10; ++i)
		zombieHorde[i].announce();

	// Zombie	*errZombieHorde;
	// errZombieHorde = z.zombieHorde(-1, "error");
	
	delete	[]zombieHorde;
}