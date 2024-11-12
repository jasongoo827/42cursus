#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Cat sound!\n";
}

std::string	WrongCat::getType() const
{
	return (type);
}