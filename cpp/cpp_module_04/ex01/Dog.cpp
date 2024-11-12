#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Default Constructor called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other)
{
	brain = new Brain(*other.getBrain());
	std::cout << "Dog Copy Constructor called\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	delete brain;
	this->brain = new Brain(*rhs.getBrain());
	return (*this);
}

Dog::~Dog()
{
	delete brain;
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

Brain* 	Dog::getBrain() const
{
	return (brain);
}
