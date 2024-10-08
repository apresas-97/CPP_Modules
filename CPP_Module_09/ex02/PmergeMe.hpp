#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>

#define BEFORE 0
#define AFTER 1

#define LIST 0
#define VECTOR 1

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );

	private:

};


template<typename T>
void	mergeInsertionSort( T &array, int size )
{
	// Step 1: Pair

	// Step 2: Compare pairs

	// Step 3: Merge largest elements of all pairs into a new array

	// Step 4: Repeat until there is only one element left

}

#endif // PMERGEME_HPP
