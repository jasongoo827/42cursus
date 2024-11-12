#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	static int rand_num = std::rand() % 3;
	
	if (rand_num == 0)
		return (dynamic_cast<Base *>(new A));
	else if (rand_num == 1)
		return (dynamic_cast<Base *>(new B));
	else
		return (dynamic_cast<Base *>(new C));
}

void identify(Base* p)
{
	std::cout << "identify by pointer\n";

	A* pA = dynamic_cast<A*>(p);
	if (pA == NULL)
		std::cout << "not type A!\n";
	else
		std::cout << "type A!\n";

	B* pB = dynamic_cast<B*>(p);
	if (pB == NULL)
		std::cout << "not type B!\n";
	else
		std::cout << "type B!\n";
	
	C* pC = dynamic_cast<C*>(p);
	if (pC == NULL)
		std::cout << "not type C!\n";
	else
		std::cout << "type C!\n";
}

void identify(Base& p)
{
	std::cout << "identify by reference\n";
	
	try
	{
		A& rA = dynamic_cast<A&>(p);
		(void)rA;
		std::cout << "type A!\n";
	}
	catch(const std::exception& exp)
	{
		std::cout << "not type A!\n";
	}
	try
	{
		B& rB = dynamic_cast<B&>(p);
		(void)rB;
		std::cout << "type B!\n";
	}
	catch(const std::exception& exp)
	{
		std::cout << "not type B!\n";
	}
	try
	{
		C& rC = dynamic_cast<C&>(p);
		(void)rC;
		std::cout << "type C!\n";
	}
	catch(const std::exception& exp)
	{
		std::cout << "not type C!\n";
	}
}

int main(void)
{
	Base* base = generate();

	identify(base);
	identify(*base);
}