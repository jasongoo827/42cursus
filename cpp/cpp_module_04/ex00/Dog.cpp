#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Default Constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog Copy Constructor called\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bow wowowowowowowoowowowowowowowowow\n";
}

std::string	Dog::getType() const
{
	return (type);
}