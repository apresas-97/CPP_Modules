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
		// void	mergeInsertionSort( vector::iterator first, vector::iterator last );
		void	mergeInsertionSort( list & lst );
		// void	mergeInsertionSort( list::iterator first, list::iterator last );

		void	printTimeElapsed( void );

	private:

		long			_elementsCount[2];
		double			_timeElapsed[2];
		std::string		_timeUnit;
		double			_timeMultiplier;
		size_t			_jacobsthalNumbers[63];

		void	mergeInsertionSort( LIterator<uint_t> first, LIterator<uint_t> last );
		void	sortAdjacentPairs( LIterator<uint_t> start, LIterator<uint_t> end );
		void	initialiseChain( std::list<LIterator<uint_t> > & chain, std::list<std::list<LIterator<uint_t> >::iterator> & chainPositions, LIterator<uint_t> start, LIterator<uint_t> end, bool isSizeOdd );
		void	insertElements( std::list<LIterator<uint_t> > & chain, std::list<std::list<LIterator<uint_t> >::iterator> & chainPositions, LIterator<uint_t> current );
		std::list<LIterator<uint_t> >::iterator	binarySearch( std::list<LIterator<uint_t> >::iterator left, std::list<LIterator<uint_t> >::iterator right, unsigned int val );
		void	passChainToIterator( std::list<LIterator<uint_t> > chain, LIterator<uint_t> start, LIterator<uint_t> last );
		void	swapLIterator( LIterator<uint_t> lhs, LIterator<uint_t> rhs );

		void	mergeInsertionSort( VIterator first, VIterator last );
		void	sortAdjacentPairs( VIterator start, VIterator end );
		void	initialiseChain( std::vector<VIterator> & chain, std::vector<std::vector<VIterator>::iterator> & chainPositions, VIterator start, VIterator end, size_t size, bool isSizeOdd );
		void	insertElements( std::vector<VIterator> & chain, std::vector<std::vector<VIterator>::iterator> & chainPositions, VIterator current );
		std::vector<VIterator>::iterator	binarySearch( std::vector<VIterator>::iterator left, std::vector<VIterator>::iterator right, unsigned int val );
		void	passChainToIterator( std::vector<VIterator> chain, VIterator start, VIterator last );
		void	swapVIterator( VIterator lhs, VIterator rhs );
	
		void	setTimeUnit( void );
		void	initJacobsthalNumbers( void );

		void	mergeIteratorToContainer( VIterator first, VIterator last, vector::iterator vstart );
		void	mergeIteratorToContainer( LIterator<uint_t> first, LIterator<uint_t> last, list::iterator lstart );

		// template<class Iterator>
		// void	mergeInsertionSortImpl( Iterator first, Iterator last );

		// template<class Iterator>
		// bool	isSorted( Iterator first, Iterator last );

		// template<class Iterator>
		// void	sortAdjacentPairs( Iterator start, Iterator end );

		// template<class Iterator>
		// void	swapIterator( Iterator lhs, Iterator rhs );

		// template<class Iterator>
		// void	initialiseChain(	std::list<Iterator> & chain,
		// 							std::vector<typename std::list<Iterator>::iterator> & chainPositions,
		// 							Iterator start,
		// 							Iterator end,
		// 							size_t size );

		// template<class Iterator>
		// typename std::list<Iterator>::iterator	binarySearch(
		// 						typename std::list<Iterator>::iterator left,
		// 						typename std::list<Iterator>::iterator right,
		// 						unsigned int val );

		// template<class Iterator>
		// void	insertElements(	std::list<Iterator> & chain,
		// 						std::vector<typename std::list<Iterator>::iterator> & chainPositions,
		// 						Iterator current,
		// 						bool isSizeOdd );

		// template<class Iterator>
		// void	passChainToIterator(	std::list<Iterator> chain,
		// 								Iterator start,
		// 								Iterator last );

		// template<class Iterator>
		// void	printIterator( Iterator start, Iterator end );
		// template<class Iterator>
		// void	printIterator( Iterator start, Iterator end, Iterator last );

};

// #include "mergeInsertionSort.tpp"

#endif // PMERGEME_HPP