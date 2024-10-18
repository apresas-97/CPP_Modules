#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

#include "VIterator.hpp"

typedef std::vector<unsigned int> vector;
typedef std::list<unsigned int> list;

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );

		size_t	jacobsthalNumbers[63];
		size_t	jacobsthalDiff[63];

		void	mergeInsertionSort( vector & vec );
		void	mergeInsertionSort( vector::iterator & first, vector::iterator & last );
		void	mergeInsertionSort( list & lst );
		void	mergeInsertionSort( list::iterator & first, list::iterator & last );

	private:

		int	comparisons;

		std::list<VIterator>::iterator	my_upper_bound(std::list<VIterator>::iterator first, std::list<VIterator>::iterator last, unsigned int val );

		void	initJacobsthalNumbers( void );
		void	initJacobsthalDiff( void );

		void	mergeInsertionSort( VIterator first, VIterator last );

};

#endif // PMERGEME_HPP