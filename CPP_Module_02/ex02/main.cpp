#include "Fixed.hpp"
#include <iostream>
#include <string>

void	testComparison( std::string op );

int	main( void )
{
	// OG:
		// Fixed a;

	// std::cout << " Testing ++ operation: " << std::endl;

	// std::cout << "Init a = " << a << std::endl;
	// std::cout << "   ++a = " << ++a << std::endl;
	// std::cout << "     a = " << a << std::endl;
	// std::cout << "   a++ = " << a++ << std::endl;
	// std::cout << "     a = " << a << std::endl;

	// std::cout << " Testing -- operation: " << std::endl;

	// std::cout << "   --a = " << --a << std::endl;
	// std::cout << "     a = " << a << std::endl;
	// std::cout << "   a-- = " << a-- << std::endl;
	// std::cout << "     a = " << a << std::endl;

	// std::cout << " Testing + operation: " << std::endl;

	// Fixed b( 1.5f );
	// Fixed c( 4.5f );
	// Fixed d( 1.914f );

	// std::cout << "b( 1.5f ) = " << b << std::endl;
	// std::cout << "c( 4.5f ) = " << c << std::endl;
	// std::cout << "d( 1.914f ) = " << d << std::endl;
	// std::cout << "b + c = " << b + c << std::endl;
	// std::cout << "b + b + b = " << b + b + b << std::endl;
	// std::cout << "b + c + d = " << b + c + d << std::endl;

	// std::cout << " Testing - operation: " << std::endl;

	// std::cout << "b - c = " << b - c << std::endl;
	// std::cout << "d - b = " << d - b << std::endl;

	// std::cout << " Testing * operation: " << std::endl;

	// std::cout << "b * c = " << b * c << std::endl;
	// std::cout << "a * d = " << a * d << std::endl;
	// Fixed e( b * c );
	// std::cout << "e(b * c) = " << e << std::endl;

	// std::cout << " Testing / operation: " << std::endl;

	// std::cout << "b / c = " << b / c << std::endl;

	// std::cout << " Testing comparison operators: " << std::endl;
	// std::cout << " Testing == operator " << std::endl;

	// std::cout << "b == c:" << std::endl;
	// if (b == c)
	// 	std::cout << "    TRUE" << std::endl;
	// else
	// 	std::cout << "    FALSE" << std::endl;

	// std::cout << "e == (b * c):" << std::endl;
	// if (e == (b * c))
	// 	std::cout << "    TRUE" << std::endl;
	// else
	// 	std::cout << "    FALSE" << std::endl;

	// std::cout << " Testing != operator " << std::endl;

	// std::cout << "e != (b * c):" << std::endl;
	// if (e != (b * c))
	// 	std::cout << "    TRUE" << std::endl;
	// else
	// 	std::cout << "    FALSE" << std::endl;

	// std::cout << "a != d:" << std::endl;
	// if (a != d)
	// 	std::cout << "    TRUE" << std::endl;
	// else
	// 	std::cout << "    FALSE" << std::endl;
	
	// std::cout << " Testing > operator " << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
