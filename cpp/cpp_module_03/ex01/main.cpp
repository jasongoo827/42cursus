#include "ScavTrap.hpp"

int main(void)
{
	{
		std::cout << "TEST 1\n";
		ScavTrap st1("jgoo");

		st1.printTrapInfo();
		st1.attack("inghwang");
		st1.guardGate();
		st1.printTrapInfo();
	}
	{
		std::cout << "\nTEST 2\n";
		ScavTrap st1("jgoo");

		st1.printTrapInfo();
		st1.takeDamage(10); // clap trap의 takeDamage 호출
		st1.guardGate();
		st1.printTrapInfo();
	}
}