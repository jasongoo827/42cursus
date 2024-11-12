#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int num);
	Fixed(const float num);
	Fixed&	operator=(const Fixed& rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		getFactor(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int	iNum;
	static const int fBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif