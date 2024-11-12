#include "HumanA.hpp"
#include "HumanB.hpp"

// void check_leak(void)
// {
// 	system("leaks ex01");
// }

int main(void)
{
	// atexit(check_leak);
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		HumanB jgoo("jgoo");
		jgoo.attack();
	}
	return 0;
}