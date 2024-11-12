#include "ClapTrap.hpp"

int main(void)
{
	{
		std::cout << "TEST 1\n";
		ClapTrap ct1("jgoo");

		std::cout << "PRINT TRAP INFO\n";
		ct1.printTrapInfo();

		std::cout << "CLAPTRAP TEST\n";
		ct1.attack("inghwang");
		ct1.setAttackDamage(10);
		ct1.attack("inghwang");
		ct1.takeDamage(5);
		ct1.beRepaired(10);
		std::cout << '\n';

		std::cout << "PRINT TRAP INFO\n";
		ct1.printTrapInfo();
	}
	{
		std::cout << "\nTEST 2\n";
		ClapTrap ct1("jgoo");

		std::cout << "PRINT TRAP INFO\n";
		ct1.printTrapInfo();

		std::cout << "CLAPTRAP TEST\n";
		ct1.attack("yakim");
		ct1.setAttackDamage(10);
		ct1.attack("yakim");
		ct1.takeDamage(15);
		ct1.beRepaired(10);
		ct1.takeDamage(5);
		std::cout << '\n';

		std::cout << "PRINT TRAP INFO\n";
		ct1.printTrapInfo();
	}
}