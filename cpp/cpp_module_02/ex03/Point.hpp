#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Fixed& f1, const Fixed& f2);
	Point(const Point& other);
	Point& operator=(const Point& rhs);
	~Point();

	Fixed	getXValue() const;
	Fixed	getYValue() const;

private:
	Fixed const x;
	Fixed const y;
};

Fixed	sign(Point const a, Point const b, Point const c);
bool 	bsp(Point const a, Point const b, Point const c, Point const point);

#endif