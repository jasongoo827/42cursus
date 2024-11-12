#include "DiamondTrap.hpp"

int main(void)
{
	{
		std::cout << "TEST 1\n";
		DiamondTrap	dt1("jgoo");

		dt1.printTrapInfo();
		dt1.attack("inghwang");
		dt1.whoAmI();
	}
	{
		std::cout << "\nTEST 2\n";

		ClapTrap cp("jgoo");
		cp.attack("yakim");
	}
}