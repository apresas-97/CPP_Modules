#include "operators.hpp"

int	main( void )
{
	Object	obj1(42);
	Object	obj2(21);

	obj1[0] = 84;
	obj2[0] = 42;

	std::cout << "obj1[0]: " << obj1.getValue() << std::endl;
	std::cout << "obj2: " << obj2.getValue() << std::endl;

	return 0;
}