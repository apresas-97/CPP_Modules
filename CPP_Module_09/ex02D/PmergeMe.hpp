#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

#include "VIterator.hpp"

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );

		size_t	jacobsthalNumbers[63];
		size_t	jacobsthalDiff[63];

		void	mergeInsertionSort( std::vector<int> & vec );

	private:

		void	initJacobsthalNumbers( void );
		void	initJacobsthalDiff( void );

		void	mergeInsertionSort( VIterator first, VIterator last );

};

#endif // PMERGEME_HPP