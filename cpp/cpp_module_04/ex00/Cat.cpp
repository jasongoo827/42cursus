#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat Copy Constructor called\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow meow meow meow meow\n";
}

std::string	Cat::getType() const
{
	return (type);
}