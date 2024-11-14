#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <utility>
#include <ctime>
#include <functional>
#include <exception>

#include "PmergeMe_types.hpp"
#include "VIteratorP.hpp"
#include "LIterator.hpp"
#include "ansi.hpp"

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

		static long	jacobsthalNumber( size_t k );

	private:

		size_t			_elements_count[2];
		double			_time_elapsed[2];
		double			_time_start[2];
		std::string		_time_unit;
		double			_time_multiplier;
		bool			_time_set[2];

		// time functions
		void	timeStart( int type );
		void	timeEnd( int type );
		void	setTimeUnit( void );

		// merge insertion sort functions
		void	mergeInsertionSort( LIterator first, LIterator last );
		void	mergeInsertionSort( VIteratorP first, VIteratorP last );

};

// parse_arguments.cpp
void	parseArguments( int size, char **argv, integer *numbers );

// print_container.cpp
void	printVector( vector & vec, std::string prefix );
void	printList( list & lst, std::string prefix );

// verify_sort.cpp
void	verifySort( vector & vec );
void	verifySort( list & lst );
void	verifySort( vector::const_iterator first, vector::const_iterator last );
void	verifySort( list::iterator first, list::iterator last );

#endif // PMERGEME_HPP