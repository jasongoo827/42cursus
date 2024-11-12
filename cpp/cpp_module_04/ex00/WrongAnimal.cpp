#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("")
{
	std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Constructor called\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound!\n";
}

std::string	WrongAnimal::getType() const
{
	return (type);
}