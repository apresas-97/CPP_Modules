#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main( void )
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	int value;
	try
	{
		value = easyfind(vec, 5);
		std::cout << "Found: " << value << std::endl;
		value = easyfind(lst, 50);
		std::cout << "Found: " << value << std::endl;
		value = easyfind(vec, 2);
		std::cout << "Found: " << value << std::endl;
		value = easyfind(lst, 10);
		std::cout << "Found: " << value << std::endl;
		value = easyfind(vec, 6);
		std::cout << "Found: " << value << std::endl;
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
