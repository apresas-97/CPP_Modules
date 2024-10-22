#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

#define BEFORE 0
#define AFTER 1

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

#include <unistd.h>

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

	PmergeMe pm;

	std::vector<unsigned int>	vec(numbers, numbers + size);
	std::vector<unsigned int>	copyVec(vec.begin(), vec.end());
	std::list<unsigned int>		lst(numbers, numbers + size);
	std::list<unsigned int>		copyLst(lst.begin(), lst.end());

	printVector(vec, "Before: ");

	// pm.mergeInsertionSort(vec);
	pm.mergeInsertionSort(vec.begin(), vec.end());
	// pm.mergeInsertionSort(lst);
	pm.mergeInsertionSort(lst.begin(), lst.end());

	printVector(vec, "After: ");

	pm.printTimeElapsed();

	std::sort(copyVec.begin(), copyVec.end(), std::less<unsigned int>());
	if (vec == copyVec)
		std::cout << GREEN "Vector is sorted" RESET << std::endl;
	else
		std::cout << RED "Vector is not sorted" RESET << std::endl;

	copyLst.sort(std::less<unsigned int>());
	if (lst == copyLst)
		std::cout << GREEN "List is sorted" RESET << std::endl;
	else
		std::cout << RED "List is not sorted" RESET << std::endl;

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
