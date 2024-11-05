#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <exception>

#include "ansi.hpp"

void	parseArguments( int size, char **argv, unsigned int *numbers )
{
	if (size < 1)
		throw std::exception();
	argv++;
	for (int i = 0; i < size; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> numbers[i];
		if (iss.fail() || !iss.eof() || argv[i][0] == '-' || numbers[i] == 0)
			throw std::exception();
	}
}

void	printVector( std::vector<unsigned int> & vec, std::string prefix )
{
	std::ostringstream oss;
	oss << prefix;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		oss << *it << " ";
	std::cout << oss.str() << std::endl;
}

void	printList( std::list<unsigned int> & lst, std::string prefix )
{
	std::ostringstream oss;
	oss << prefix;
	for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); it++)
		oss << *it << " ";
	std::cout << oss.str() << std::endl;
}

//// isSorted
bool	isSorted( std::list<unsigned int> & lst )
{
	if (lst.size() < 2)
		return true;

	std::list<unsigned int>::const_iterator it = lst.begin();
	std::list<unsigned int>::const_iterator next = it;
	++next;

	while (next != lst.end())
	{
		if (*it > *next)
			return false;
		++it;
		++next;
	}

	return true;
}

bool	isSorted( std::vector<unsigned int> & vec )
{
	if (vec.size() < 2)
		return true;
	
	for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end() - 1; ++it)
	{
		if (*it > *(it + 1))
			return false;
	}

	return true;
}
////

//// verifySort
void	verifySort( std::vector<unsigned int> & vec )
{
	if (isSorted(vec))
		std::cout << GREEN BOLD << "Vector is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "Vector is not sorted!" << RESET << std::endl;
}

void	verifySort( std::list<unsigned int> & lst )
{
	if (isSorted(lst))
		std::cout << GREEN BOLD << "List is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "List is not sorted!" << RESET << std::endl;
}
////

int	main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <elements>" << std::endl;
		return 1;
	}
	try
	{
		int				size = argc - 1;
		unsigned int	numbers[size];
		parseArguments(size, argv, numbers);

		PmergeMe	pm;

		std::vector<unsigned int>	vec(numbers, numbers + size);
		std::list<unsigned int>		lst(numbers, numbers + size);

		printVector(vec, "Before: ");

		pm.mergeInsertionSort(vec);
		pm.mergeInsertionSort(lst);

		printVector(vec, "After: ");
		// printList(lst, "After: ");

		pm.printTimeElapsed();

		verifySort(vec);
		verifySort(lst);

	}
	catch ( const std::exception & e )
	{
		std::cout << "Error" << std::endl;
	}
	return 0;
}