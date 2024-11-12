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
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);

	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;

	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;

	Fixed	&operator++(void);
	Fixed	&operator--(void);
	// 중첩 연산을 막기 위해 const로 return
	const Fixed operator++(int);
	const Fixed operator--(int);

	static Fixed&	max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
	static Fixed&	min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);

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