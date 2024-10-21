#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

#define BEFORE 0
#define AFTER 1

void	printVector( std::vector<unsigned int> & vec, std::string prefix );
void	printList( std::list<unsigned int> & lst, std::string prefix );
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
	std::vector<unsigned int> vec(numbers, numbers + size);
	std::vector<unsigned int> copy(vec.begin(), vec.end());

	std::cout << "Sorting as a vector:" << std::endl;
	printVector(vec, "Before: ");

	PmergeMe pm;
	// pm.mergeInsertionSort(vec);
	pm.mergeInsertionSort(vec.begin(), vec.end());

	printVector(vec, "After: ");
	pm.printTimeElapsed();

	std::sort(copy.begin(), copy.end(), std::less<unsigned int>());

	if (vec == copy)
		std::cout << "Vectors are equal" << std::endl;
	else
		std::cout << "Vectors are not equal" << std::endl;

	delete [] numbers;
	return 0;
}

void	printVector( std::vector<unsigned int> & vec, std::string prefix )
{
	std::stringstream ss;
	ss << prefix;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		ss << *it << " ";
	std::cout << ss.str() << std::endl;
}

void	printList( std::list<unsigned int> & lst, std::string prefix )
{
	std::stringstream ss;
	ss << prefix;
	for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); it++)
		ss << *it << " ";
	std::cout << ss.str() << std::endl;
}
