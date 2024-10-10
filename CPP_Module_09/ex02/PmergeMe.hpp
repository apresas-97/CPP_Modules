#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

#include "pair_utils.hpp"
#include "utils_idk.hpp"

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

size_t	getNextJacobsthalNumber( void )
{
	static size_t	currentNumber = 0;
	static size_t	nextNumber = 1;
	size_t			tmp = currentNumber;

	currentNumber = nextNumber;
	nextNumber += 2 * tmp;

	return tmp;
}

// mergeInsertionSort, called with just the container to be sorted
void	mergeInsertionSort( std::vector<int> & container )
{
	mergeInsertionSortVector(container.begin(), container.end());
}

void	mergeInsertonSort( std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end );

// mergeInsertionSort, called with iterators
template<typename Iterator>
void	mergeInsertionSortVector( Iterator begin, Iterator end )
{
	size_t	size = std::distance(begin, end);
	if (size < 2) // Maybe?
		return ;


	// Maybe have a bool has_stray if size is odd, then
	// redefine end to be end - 1, but keep track of the original end

	// Step 1: Create pairs
	size_t	nbPairs = size / 2;
	std::vector<std::pair<int, int> >	mainChain = makePairVector(begin, end);
	sortPairs(mainChain, std::less<int>>()); // Suspicious

	// Sort it recursively (based on their lowest value(which is the first element, since we just sorted them like such))
	if (mainChain.size() > 1)
		mergeInsertionSortVector(mainChain.begin(), mainChain.end());

	// After you have come out of the recursion, you must merge the pairs
	// into the original container I think

	// Insert b1, which will always be smaller than a1
	std::vector<int> vecChain;
	for (size_t i = 0; i < mainChain.size(); i++)
		vecChain.push_back(mainChain[i].first);

	// insert b1
	
	size_t	b_end = size - vecChain.size() - 1;
	size_t	i = b_end - getNextJacobsthalNumber();
	vecChain.push_back(mainChain[i].second); // push b1
	while (i >= 0)
	{
		size_t	i = b_end - getNextJacobsthalNumber();
		size_t	next_end = 0;
		while (i != b_end)
		{
			binaryInsert(vecChain, mainChain[i].second);
			next_end++;
			i++;
		}
		b_end -= next_end;
	}

}

void	binaryInsert( std::vector<int> & vec, int value )
{
	size_t	i = vec.size() - 2;
	if (value >= vec[i])
	{
		if (value >= vec[i + 1])
			vec.push_back(value);
		else // value < vec[i + 1]
			vec.insert(vec.begin() + (i + 1), value);
	}
	else // value < vec[i]
	{
		if (value >= vec[i - 1])
			vec.insert(vec.begin() + i, value);
		else // value < vec[i - 1]
			vec.insert(vec.begin() + (i - 1), value);
	}
}


// void	mergeInsertonSort( std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end )
// {
// 	// Step 1: Create pairs
// 	// How many pairs?
// 	std::vector<std::pair<int, int> >	pairs;
// 	std::vector<std::pair<int, int> >::iterator	it = begin; // necessary? or can I use begin directly?

// 	size_t	nbPairs = (end - begin) / 2;
// 	for (size_t i = 0; i < nbPairs; i++)
// 	{
// 		pairs.push_back(std::make_pair(it->first, (it + 1)->first));
// 		sortPair(pairs[i]);
// 	}

// 	std::vector<std::pair<int, int> >	mainChain;
// 	for (size_t i = 0; i < nbPairs; i++)
// 		mainChain.push_back(pairs[i]);
// 	// ??

// 	// Sort it recursively
// 	if (mainChain.size() > 1)
// 		mergeInsertionSortVector(mainChain.begin(), mainChain.end());
// }


// template<typename T>
// void	mergeInsertionSort( typename T::iterator begin, typename T::iterator end )
// {
// 	// Step 1: Pair
// 	// How many pairs?
// 	unsigned int	nbPairs = (end - begin) / 2;
// 	std::cout << "nbPairs = " << nbPairs << std::endl;
// 	std::pair<int, int>			pair[nbPairs];
// 	typename T::iterator		it = begin;
// 	unsigned int	i = 0;
// 	while (it != end)
// 	{
// 		pair[i].first = *it;
// 		it++;
// 		if (it != end)
// 		{
// 			pair[i].second = *it;
// 			it++;
// 		}
// 		i++;
// 	}

// 	std::cout << "Pairs before sorting:" << std::endl;
// 	printPairs(pair, nbPairs);
// 	std::cout << std::endl;

// 	// Step 2: Compare pairs
// 	for (unsigned int i = 0; i < nbPairs; i++)
// 		sortPair(pair[i]);

// 	std::cout << "Pairs after sorting:" << std::endl;
// 	printPairs(pair, nbPairs);
// 	std::cout << std::endl;

// 	// Step 3: Merge largest elements of all pairs into a new array
// 	std::vector<std::pair<int, int> >	mainChain;
// 	for (unsigned int i = 0; i < nbPairs; i++)
// 		mainChain.push_back(pair[i]);
	
// 	// Sort it recursively
// 	if (mainChain.size() > 1)
// 		mergeInsertionSort<std::vector<std::pair<int, int>>>(mainChain.begin(), mainChain.end());

// 	// Step 4: Repeat until there is only one element left
// }

#endif // PMERGEME_HPP
