#include "Point.hpp"

// void check_leak(void)
// {
// 	system("leaks ex03");
// }

int main(void)
{
	// atexit(check_leak);
	Point a(Fixed(0), Fixed(0));
	std::cout << "Point a coordinate (x, y) = ";
	std::cout << "("<< a.getXValue() << ", " << a.getYValue() << ")" << std::endl;
	Point b(Fixed(3), Fixed(0));
	std::cout << "Point b coordinate (x, y) = ";
	std::cout << "("<< b.getXValue() << ", " << b.getYValue() << ")" << std::endl;
	Point c(Fixed(1.5f), Fixed(3));
	std::cout << "Point c coordinate (x, y) = ";
	std::cout << "("<< c.getXValue() << ", " << c.getYValue() << ")" << std::endl;

	std::cout << "\nTEST 1 - check if Point p is in Triangle abc\n";
	Point p(Fixed(1.5f), Fixed(1));
	std::cout << "Point p coordinate (x, y) = ";
	std::cout << "("<< p.getXValue() << ", " << p.getYValue() << ")" << std::endl;
	if (::bsp(a, b, c, p))
		std::cout << "Point is in the triangle!\n";
	else
		std::cout << "Point is not in the triangle!\n";

	std::cout << "\nTEST 2 - check if Point z is in Triangle abc\n";
	Point z(Fixed(3.5f), Fixed(3.5f));
	std::cout << "Point z coordinate (x, y) = ";
	std::cout << "("<< z.getXValue() << ", " << z.getYValue() << ")" << std::endl;
	if (::bsp(a, b, c, z))
		std::cout << "Point is in the triangle!\n";
	else
		std::cout << "Point is not in the triangle!\n";
	
	std::cout << "\nTEST 3 - check Point operator=\n";
	Point X;
	X = z;
	std::cout << "Point X coordinate (x, y) = ";
	std::cout << "("<< X.getXValue() << ", " << X.getYValue() << ")" << std::endl;
}