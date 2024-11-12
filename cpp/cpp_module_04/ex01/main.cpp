#include "Dog.hpp"
#include "Cat.hpp"

// void check_leak(void)
// {
// 	system("leaks ex01");
// }

int main(void)
{
	// atexit(check_leak);
	{
		std::cout << "TEST1: CHECK CLASSES\n";
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
		std::cout << '\n';
	}
	{
		std::cout << "TEST2: CHECK ANIMAL ARRAY\n";
		Animal** animalArray = new Animal*[10];
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "Create Animal " << i + 1 << '\n';
			animalArray[i] = new Dog();
		}
		for (int i = 5; i < 10; ++i)
		{
			std::cout << "Create Animal " << i + 1 << '\n';
			animalArray[i] = new Cat();
		}
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "Delete Animal " << i + 1 << " :" << animalArray[i]->getType() << '\n';
			delete animalArray[i];
		}
		delete []animalArray;
	}
	{
		std::cout << "\nTEST3: CHECK DOG COPY CONSTRUCTOR\n";
		const Dog d1;
		const Animal* a = new Dog(d1);
		a->makeSound();
		delete a;
	}
	{
		std::cout << "\nTEST4: CHECK CAT COPY CONSTRUCTOR\n";
		const Cat c1;
		const Animal* b = new Cat(c1);
		b->makeSound();
		delete b;
	}
	{
		std::cout << "\nTEST5: CHECK DOG COPY OPERATOR\n";
		const Dog d1;
		Animal* a = new Dog();
		*a = d1;
		a->makeSound();
		delete a;
	}
	return 0;
}