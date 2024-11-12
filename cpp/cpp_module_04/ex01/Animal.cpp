#include "Animal.hpp"

Animal::Animal(): type("")
{
	std::cout << "Animal Default Constructor called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy Constructor called\n";
	this->type = other.getType();
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "No sound!\n";
}

std::string	Animal::getType() const
{
	return (type);
}