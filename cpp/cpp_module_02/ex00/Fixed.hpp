#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int	iNum;
	static const int fBits = 8;
};

#endif