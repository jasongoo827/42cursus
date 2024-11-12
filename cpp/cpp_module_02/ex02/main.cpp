#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	a2(2);
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(42.42f) + Fixed(12.9f));
	Fixed const d(Fixed(42.42f) - Fixed(12.9f));
	Fixed const e(Fixed(42.42f) / Fixed(12.9f));

	std::cout << "TEST FOR INCREMENT / DECREMENT OPERATOR\n";
	std::cout << "a = ";
	std::cout << a << std::endl;
	std::cout << "++a = ";
	std::cout << ++a << std::endl;
	std::cout << "a = ";
	std::cout << a << std::endl;
	std::cout << "a++ = ";
	std::cout << a++ << std::endl;
	std::cout << "a = ";
	std::cout << a << std::endl;
	std::cout << "\n";

	std::cout << "TEST FOR CALCULATE OPERATOR\n";
	std::cout << "b(Fixed(5.05f) * Fixed(2)) = ";
	std::cout << b << std::endl;
	std::cout << "c(Fixed(42.42f) + Fixed(12.9f)) = ";
	std::cout << c << std::endl;
	std::cout << "d(Fixed(42.42f) - Fixed(12.9f)) = ";
	std::cout << d << std::endl;
	std::cout << "e(Fixed(42.42f) / Fixed(12.9f)) = ";
	std::cout << e << std::endl;
	std::cout << "\n";

	std::cout << "TEST FOR MAX / MIN FUNCTION\n";
	std::cout << "::max(a, a2) = ";
	std::cout << Fixed::max(a, a2) << std::endl;
	std::cout << "::min(a, a2) = ";
	std::cout << Fixed::min(a, a2) << std::endl;

	std::cout << "::max(a, b) = ";
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "::min(c, d) = ";
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << "\n";

}