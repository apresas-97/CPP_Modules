#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void )
{
	Point const a(10, 0);
	Point const b(0, 0);
	Point const c(10, 10);
	Point const point(5.1f, 5);

	if (bsp(a, b, c, point) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	return 0;
}
