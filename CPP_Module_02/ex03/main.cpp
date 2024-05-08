#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void )
{
	Point const a(10, 0);
	Point const b(0, 0);
	Point const c(10, 10);
	Point const pointOut(4.99f, 5);
	Point const pointEdge(5, 5);
	Point const pointIn(5.01f, 5);

	std::cout << "Checking if point (" << pointOut.getX() << ", " << pointOut.getY() << ") is inside the triangle" << std::endl;
	if (bsp(a, b, c, pointOut) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	std::cout << "Checking if point (" << pointEdge.getX() << ", " << pointEdge.getY() << ") is inside the triangle" << std::endl;
	if (bsp(a, b, c, pointEdge) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	std::cout << "Checking if point (" << pointIn.getX() << ", " << pointIn.getY() << ") is inside the triangle" << std::endl;
	if (bsp(a, b, c, pointIn) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	return 0;
}
