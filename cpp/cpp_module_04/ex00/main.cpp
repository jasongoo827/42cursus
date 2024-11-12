#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void check_leak(void)
// {
// 	system("leaks ex00");
// }

int main(void)
{
	// atexit(check_leak);

	std::cout << "TEST 1: Correct Case\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\nTEST 2: Wrong Case (No Virtual Keyword)\n";
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << wcat->getType() << " " << std::endl;

	wcat->makeSound();
	wmeta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wmeta;
	delete wcat;

	return 0;
}