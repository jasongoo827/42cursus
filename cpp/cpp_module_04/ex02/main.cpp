#include "Dog.hpp"
#include "Cat.hpp"

// void check_leak(void)
// {
// 	system("leaks ex02");
// }

int main(void)
{
	// atexit(check_leak);

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	delete j;
	delete i;

	// impossible case
	// Animal* animal = new Animal();

	return 0;
}