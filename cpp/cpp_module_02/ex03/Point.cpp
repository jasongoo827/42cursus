#include "Point.hpp"

Point::Point(): x(0), y(0)
{

}

Point::Point(const Fixed& f1, const Fixed& f2): x(f1), y(f2)
{

}

Point::Point(const Point& other): x(other.getXValue()), y(other.getYValue())
{

}

Point& Point::operator=(const Point& rhs)
{
	if (this == &rhs)
		return (*this);
	this->~Point();
    new(this) Point(rhs.getXValue(), rhs.getYValue());
	return (*this);
}

Point::~Point()
{

}

Fixed	Point::getXValue() const
{
	return (this->x);
}

Fixed	Point::getYValue() const
{
	return (this->y);
}