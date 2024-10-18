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
	std::cout << "Sorting as a vector:" << std::endl;
	std::vector<unsigned int> vec(numbers, numbers + size);
	printVector(vec, "Before: ");

	PmergeMe pm;
	pm.mergeInsertionSort(vec);

	printVector(vec, "After: ");

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
