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
#include "LIterator.hpp"

typedef std::vector<unsigned int> vector;
typedef std::list<unsigned int> list;
typedef std::list<VIterator> VIteratorList;
typedef std::list<LIterator> LIteratorList;

#define VECTOR 0
#define LIST 1

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

		long			_elementsCount[2];
		double			_timeElapsed[2];
		size_t			_jacobsthalNumbers[63];

		void	initJacobsthalNumbers( void );

		bool	isSorted( VIterator first, VIterator last );
		bool	isSorted( LIterator first, LIterator last );

		void	sortAdjacentPairs( VIterator start, VIterator end );
		void	sortAdjacentPairs( LIterator start, LIterator end );

		void	mergeInsertionSort( VIterator first, VIterator last );
		void	mergeInsertionSort( LIterator first, LIterator last );

		void	mergeIteratorToContainer( VIterator first, VIterator last, vector::iterator vstart );
		void	mergeIteratorToContainer( LIterator first, LIterator last, list::iterator lstart );

		void	passChainToIterator( std::list<VIterator> chain, VIterator start, VIterator last );
		void	passChainToIterator( std::list<LIterator> chain, LIterator start, LIterator last );

		VIteratorList::iterator	binarySearch(VIteratorList::iterator left, VIteratorList::iterator right, unsigned int val );
		LIteratorList::iterator	binarySearch(LIteratorList::iterator left, LIteratorList::iterator right, unsigned int val );

};

#endif // PMERGEME_HPP