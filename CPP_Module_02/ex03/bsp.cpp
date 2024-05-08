#include "Point.hpp"
#include "Fixed.hpp"

Fixed	partition( Point const a, Point const b, Point const point )
{
	return (((point.getX() - a.getX()) * (b.getY()- a.getY())) - ((point.getY() - a.getY()) * (b.getX() - a.getX())));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	ab = partition(a, b, point);
	Fixed	bc = partition(b, c, point);
	Fixed	ca = partition(c, a, point);
	// std::cout << "ab = " << ab << std::endl;
	// std::cout << "bc = " << bc << std::endl;
	// std::cout << "ca = " << ca << std::endl;

	if ((ab < 0 && bc < 0 && ca < 0) || (ab > 0 && bc > 0 && ca > 0))
		return true;
	return false;
}
