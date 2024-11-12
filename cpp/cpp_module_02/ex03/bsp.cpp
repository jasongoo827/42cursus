#include "Point.hpp"

Fixed	sign(Point const a, Point const b, Point const c)
{
	return ((a.getXValue() - c.getXValue()) * (b.getYValue() - c.getYValue()) -
         (b.getXValue() - c.getXValue()) * (a.getYValue() - c.getYValue()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	if ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0))
		return (true);
	return (false);
}