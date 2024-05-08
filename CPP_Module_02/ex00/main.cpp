#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed a;
	a.setRawBits(10);
	Fixed b( a );
	std::cout << b.getRawBits() << std::endl;

	Fixed c;
	std::cout << c.getRawBits() << std::endl;

	c = b;
	std::cout << c.getRawBits() << std::endl;

	b.setRawBits(20);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
