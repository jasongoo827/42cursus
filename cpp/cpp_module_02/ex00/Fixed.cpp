#include "Fixed.hpp"

Fixed::Fixed(): iNum(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";

	*this = other;
	// this->iNum = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Copy assignment operator called\n";
	this->iNum = rhs.getRawBits();
	return (*this);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (iNum);
}

void	Fixed::setRawBits(int const raw)
{
	iNum = raw;
	std::cout << "setRawBits member function called\n";
}