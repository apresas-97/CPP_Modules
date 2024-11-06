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
#include <functional>

#include "VIteratorP.hpp"
#include "LIterator.hpp"
#include "ansi.hpp"

typedef std::list<unsigned int>					list;
typedef std::pair<unsigned int, unsigned int>	pair_t;
typedef std::vector<unsigned int>				vector;
typedef std::vector<pair_t>						vector_pair;

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
		// void	mergeInsertionSort( list::iterator first, list::iterator last );

		void	printTimeElapsed( void );

	private:

		size_t			_elementsCount[2];
		double			_timeElapsed[2];
		double			_timeStart[2];
		std::string		_timeUnit;
		double			_timeMultiplier;
		// size_t			_jacobsthalNumbers[63];

		// long	getJacobsthalNumber( unsigned int k );

		// time functions
		void	timeStart( int type );
		void	timeEnd( int type );
		void	setTimeUnit( void );

		// merge insertion sort functions
		void	mergeInsertionSort( LIterator first, LIterator last );
		void	mergeInsertionSort( VIteratorP first, VIteratorP last );
		
		// void	initJacobsthalNumbers( void );

};

long	jacobsthalNumber( unsigned int k );

#endif // PMERGEME_HPP