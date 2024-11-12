#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other)
{
	brain = new Brain(*other.getBrain());
	std::cout << "Cat Copy Constructor called\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	delete brain;
	this->brain = new Brain(*rhs.getBrain());
	return (*this);
}

Cat::~Cat()
{
	delete brain;
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

Brain* Cat::getBrain() const
{
	return (brain);
}