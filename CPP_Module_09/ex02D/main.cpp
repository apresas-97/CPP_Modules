#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

void	printVector( std::vector<int> & vec );

int	main( void )
{
	std::vector<int>	vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(6);
	
	printVector(vec);

	PmergeMe	pm;
	pm.mergeInsertionSort(vec);

	printVector(vec);

	return 0;
}

void	printVector( std::vector<int> & vec )
{
	std::stringstream ss;
	ss << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		ss << *it << " ";
	std::cout << ss.str() << std::endl;
}
