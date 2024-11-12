#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// void check_leak(void)
// {
// 	system("leaks ex03");
// }

int main(void)
{
	// atexit(check_leak);
	{
		std::cout << "TEST 1: SUBJECT EXAMPLE\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\nTEST 2: TEST unequip function\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("jgoo");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->unequip(1);
		delete tmp; // 명시적으로 delete

		ICharacter* bob = new Character("yakim");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\nTEST 3: TEST inventory\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("jgoo");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("Amateria");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;

		ICharacter* bob = new Character("yakim");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\nTEST 4: TEST DEEP COPY\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("jgoo");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* clone = new Character(*static_cast<Character*>(me));
		clone->use(0, *me);
		clone->use(1, *me);
		clone->use(2, *me);
		clone->use(3, *me);

		Character clone_clone;
		clone_clone = *static_cast<Character*>(clone);
		clone_clone.use(0, *me);
		clone_clone.use(1, *me);
		clone_clone.use(2, *me);
		clone_clone.use(3, *me);

		delete clone;
		delete me;
		delete src;
	}
}