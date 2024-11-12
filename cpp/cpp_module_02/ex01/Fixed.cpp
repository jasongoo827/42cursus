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

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	
	this->iNum = num * getFactor();
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";

	this->iNum = roundf(num * getFactor());
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	return (iNum);
}

void	Fixed::setRawBits(int const raw)
{
	iNum = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(iNum) / this->getFactor());
}

int		Fixed::toInt(void) const
{
	return (iNum / this->getFactor());
}

int		Fixed::getFactor(void) const
{
	int	factor = 1;
	for (int i = 0; i < this->fBits; ++i)
		factor *= 2;
	return (factor);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << static_cast<float>(fixed.getRawBits()) / fixed.getFactor();
	return (out);
}