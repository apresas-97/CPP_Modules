#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>
#include <iterator>
#include <utility>
#include <ctime>

#include "VIterator.hpp"

typedef std::vector<unsigned int> vector;
typedef std::list<unsigned int> list;
typedef std::list<VIterator> VIteratorList;

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );


		void	mergeInsertionSort( vector & vec );
		void	mergeInsertionSort( vector::iterator first, vector::iterator last );
		void	mergeInsertionSort( list & lst );
		void	mergeInsertionSort( list::iterator first, list::iterator last );

		void	printTimeElapsed( void );

	private:

		double	timeElapsed;
		size_t	jacobsthalNumbers[63];
		size_t	jacobsthalDiff[63];

		VIteratorList::iterator	binarySearch(VIteratorList::iterator left, VIteratorList::iterator right, unsigned int val );

		void	initJacobsthalNumbers( void );
		void	initJacobsthalDiff( void );
		void	makePairs( VIterator start, VIterator end );

		void	mergeInsertionSort( VIterator first, VIterator last );

};

#endif // PMERGEME_HPP