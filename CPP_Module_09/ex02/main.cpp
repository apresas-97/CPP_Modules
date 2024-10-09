#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

void	printArray( bool prefix, int *array, int size );

int	main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe \"expression\"" << std::endl;
		return 1;
	}
	int	size = argc - 1;
	int	*numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::stringstream ss(argv[i + 1]);
		ss >> numbers[i];
		if (ss.fail() || !ss.eof())
		{
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
	}
	printArray(BEFORE, numbers, size);

	std::vector<int> vec(numbers, numbers + size);
	
	mergeInsertionSort<std::vector<int>>(vec.begin(), vec.end());

	printArray(AFTER, numbers, size);
	// printTime(0);
	// printTime(1);

	delete [] numbers;
	return 0;
}

void	printArray( bool prefix, int *array, int size )
{
	std::stringstream ss;
	if (prefix == BEFORE)
		ss << "Before:\t";
	else if (prefix == AFTER)
		ss << "After:\t";
	for (int i = 0; i < size; i++)
	{
		ss << array[i];
		if (i < size - 1)
			ss << " ";
	}
	std::cout << ss.str() << std::endl;
}
