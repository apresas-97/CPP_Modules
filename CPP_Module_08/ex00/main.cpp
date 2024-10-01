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
		int	to_find = 5;
		std::cout << "Attempting to find " << to_find << " in the vector:" << std::endl;
		value = easyfind(vec, to_find);
		std::cout << "Found: " << value << std::endl;
		std::cout << std::endl;
	
		to_find = 50;
		std::cout << "Attempting to find " << to_find << " in the list:" << std::endl;
		value = easyfind(lst, to_find);
		std::cout << "Found: " << value << std::endl;
		std::cout << std::endl;
	
		to_find = 6;
		std::cout << "Attempting to find " << to_find << " in the vector:" << std::endl;
		value = easyfind(vec, to_find);
		std::cout << "Found: " << value << std::endl;
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Attempting to find in an empty vector:" << std::endl;
	std::vector<int> emptyVector;
	try
	{
		value = easyfind(emptyVector, 5);
		std::cout << "Found: " << value << std::endl;
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
