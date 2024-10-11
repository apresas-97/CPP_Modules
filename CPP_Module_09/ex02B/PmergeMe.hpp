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

template<typename Container>
class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &other );
	~PmergeMe();
	PmergeMe &operator=( PmergeMe const &other );

	int &	operator[]( int index );
	int &	operator[]( int index ) const;

	typename Container::iterator	begin( void );

private:
	Container<int>	_arr;
	size_t			_elementSize;

};

template<typename Container>
int &	PmergeMe<Container>::operator[]( int index )
{
	return _arr[index * _elementSize];
}

template<typename Container>
int &	PmergeMe<Container>::operator[]( int index ) const
{
	return _arr[index * _elementSize];
}



//// pair utils
// Sorts a pair of values from within a container
template<typename Iterator, typename Comparator>
void	sortPair( Iterator pairA, Iterator pairB, Comparator comp )
{
	if (comp(*pairA, *pairB)) // If the given comparator returns true
		std::swap(*pairA, *pairB);
}

// Inserts an element using binary search, within the range from begin to end
template<typename Iterator>
void	insertElement( Iterator element, Iterator begin, Iterator end, size_t elementSize, size_t offset )
{
	// size_t	i = offset;
	// while (i < elementSize)
	// {
	// 	if (element < begin + i)
	// 	{
	// 		std::swap(*element, *(begin + i));
	// 		element = begin + i;
	// 	}
	// 	i++;
	// }
}

// void	binaryInsert( Iterator begin, Iterator end, size_t elementSize, size_t offset, int value )
// {
	
// }

// Still unsure if I should use iterators or pointers or indexes

// Swap two elements from a container, the elements can be of elementSize, since you could be sorting pairs
// Or pairs of pairs, etc.
template<typename Iterator>
void	swapElements( Iterator elementA, Iterator elementB, size_t elementSize )
{
	Iterator tmp = elementA;
	for (size_t i = 0; i < elementSize; i++)
	{
		std::swap(*elementA, *elementB);
		elementA++;
		elementB++;
	}
}

// template<typename Iterator>
// void	insertElement( Iterator element, Iterator rangeBegin, Iterator rangeEnd, size_t elementSize, size_t offset )
// {
// 	// size_t	i = offset;
// 	// while (i < elementSize)
// 	// {
// 	// 	if (element < begin + i)
// 	// 	{
// 	// 		std::swap(*element, *(begin + i));
// 	// 		element = begin + i;
// 	// 	}
// 	// 	i++;
// 	// }
// }

template<typename Iterator>
void	insertElement( Iterator begin, Iterator end, Iterator element, size_t elementSize )
{
	for (Iterator it = begin; it != end; it += elementSize)
	{
		if (*element < *it)
		{
			swapElements(element, it, elementSize);
			element = it;
		}
	}
}

template<typename Iterator>
void	mergeInsertionSort( Iterator begin, Iterator end, size_t elementSize )
{
	size_t	size = std::distance(begin, end) / elementSize;
	if (size < 2) // Maybe?
		return ;

	// Do something about the odd element?
	bool	oddSize = size % 2 != 0;
	int		lastValue = 0;
	if (oddSize)
		lastValue = *(end - 1);
	//

	// Create "pairs"
	size_t	nbPairs = size / 2;
	size_t	pairSize = elementSize * 2;
	// Sort "pairs"
	for (Iterator it = begin; it != end; it += pairSize)
		sortPair(it, it + elementSize, std::greater<int>());

	// Sort the "pairs" by their first element, recursively
	mergeInsertionSort(begin, begin + (nbPairs * pairSize), pairSize);

	// "Merge" the elements of the "pairs" into their right place
	// A pair is (a, b)
	// There are k pairs
	// The elements will be referred to as a1, b1, a2, b2, ..., ak, bk
	// a1, b1 will be the elements of the first pair
	// ak, bk will be the elements of the k-th pair
	// We will pretend that a1, a2... ak is the main chain
	// And b1, b2... bk is the pending chain. Which includes, if it exists, the last value that was unpaired

	// Insert b1, which will always be smaller than a1, so it must go first

	size_t	i = 0;
	size_t	pendSize = size - static_cast<int>(oddSize); // ?? -1 if odd? -0 if even?
	while (true) // for now
	{
		if (i + jacobsthalNumber(i) >= pendSize)
			break ;


	}


	return ;
}







// OLD APPROACH
// size_t	getNextJacobsthalNumber( void )
// {
// 	static size_t	currentNumber = 0;
// 	static size_t	nextNumber = 1;
// 	size_t			tmp = currentNumber;

// 	currentNumber = nextNumber;
// 	nextNumber += 2 * tmp;

// 	return tmp;
// }

// // mergeInsertionSort, called with just the container to be sorted
// void	mergeInsertionSort( std::vector<int> & container )
// {
// 	mergeInsertionSortVector(container.begin(), container.end());
// }

// void	mergeInsertonSort( std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end );

// // mergeInsertionSort, called with iterators
// template<typename Iterator>
// void	mergeInsertionSortVector( Iterator begin, Iterator end )
// {
// 	size_t	size = std::distance(begin, end);
// 	if (size < 2) // Maybe?
// 		return ;


// 	// Maybe have a bool has_stray if size is odd, then
// 	// redefine end to be end - 1, but keep track of the original end

// 	// Step 1: Create pairs
// 	size_t	nbPairs = size / 2;
// 	std::vector<std::pair<int, int> >	mainChain = makePairVector(begin, end);
// 	sortPairs(mainChain, std::less<int>>()); // Suspicious

// 	// Sort it recursively (based on their lowest value(which is the first element, since we just sorted them like such))
// 	if (mainChain.size() > 1)
// 		mergeInsertionSortVector(mainChain.begin(), mainChain.end());

// 	// After you have come out of the recursion, you must merge the pairs
// 	// into the original container I think

// 	// Insert b1, which will always be smaller than a1
// 	std::vector<int> vecChain;
// 	for (size_t i = 0; i < mainChain.size(); i++)
// 		vecChain.push_back(mainChain[i].first);

// 	// insert b1
	
// 	size_t	b_end = size - vecChain.size() - 1;
// 	size_t	i = b_end - getNextJacobsthalNumber();
// 	vecChain.push_back(mainChain[i].second); // push b1
// 	while (i >= 0)
// 	{
// 		size_t	i = b_end - getNextJacobsthalNumber();
// 		size_t	next_end = 0;
// 		while (i != b_end)
// 		{
// 			binaryInsert(vecChain, mainChain[i].second);
// 			next_end++;
// 			i++;
// 		}
// 		b_end -= next_end;
// 	}

// }

// void	binaryInsert( std::vector<int> & vec, int value )
// {
// 	size_t	i = vec.size() - 2;
// 	if (value >= vec[i])
// 	{
// 		if (value >= vec[i + 1])
// 			vec.push_back(value);
// 		else // value < vec[i + 1]
// 			vec.insert(vec.begin() + (i + 1), value);
// 	}
// 	else // value < vec[i]
// 	{
// 		if (value >= vec[i - 1])
// 			vec.insert(vec.begin() + i, value);
// 		else // value < vec[i - 1]
// 			vec.insert(vec.begin() + (i - 1), value);
// 	}
// }


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
