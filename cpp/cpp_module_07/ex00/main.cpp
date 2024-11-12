#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 2;
	std::cout << "TEST CASE 1\n";
	std::cout << "swap( a, b )\n";
	std::cout << "a = " << a << ", b = " << b;
	std::cout << " -> ";
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;


	std::cout << "\nTEST CASE 2: string\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "swap( c, d )\n";
	std::cout << "c = " << c << ", d = " << d;
	std::cout << " -> ";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	const int e = 2;
	const int f = 3;
	std::cout << "\nTEST CASE 3: const 매개변수\n";
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	const int g = 42;
	const int h = 31;
	const int r1 = ::min(g, h);
	const int r2 = ::max(g, h);
	std::cout << "\nTEST CASE 4: const return\n";
	std::cout << "e = " << g << ", f = " << h << std::endl;
	std::cout << "const int r1 = min( e, f ) = " << r1 << std::endl;
	std::cout << "const int r2 = max( e, f ) = " << r2 << std::endl;

	int x = 2;
	int y = 2;
	std::cout << "\nTEST CASE 5: check address\n";
	std::cout << "&x = " << &x << ", &y = " << &y << std::endl;
	std::cout << "swap( x, y )\n";
	std::cout << "x = " << x << ", y = " << y;
	std::cout << " -> ";
	::swap( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "&min( x, y ) = " << &::min( x, y ) << std::endl;
	std::cout << "&max( x, y ) = " << &::max( x, y ) << std::endl;
	
	return 0;
}