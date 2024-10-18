#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	initJacobsthalNumbers();
	initJacobsthalDiff();
}

PmergeMe::PmergeMe( PmergeMe const &other ) { *this = other; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other )
	{
		// Nothing to do here
	}
	return *this;
}

void	PmergeMe::initJacobsthalNumbers( void )
{
	jacobsthalNumbers[0] = 0;
	jacobsthalNumbers[1] = 1;
	for (size_t i = 2; i < 63; i++)
		jacobsthalNumbers[i] = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
}

void	PmergeMe::initJacobsthalDiff( void )
{
	jacobsthalDiff[0] = 2;
	jacobsthalDiff[1] = 2;
	for (size_t i = 2; i < 63; i++)
		jacobsthalDiff[i] = jacobsthalDiff[i - 1] + 2 * jacobsthalDiff[i - 2];
}

/////
bool	compare( const unsigned int & lhs, const VIterator & rhs )
{
	return lhs > *rhs;
}
#include <iterator>
#include <utility>

std::list<VIterator>::iterator	PmergeMe::my_upper_bound(std::list<VIterator>::iterator first, std::list<VIterator>::iterator last, unsigned int val )
{
	std::list<VIterator>::iterator											it;
	std::iterator_traits<std::list<VIterator>::iterator>::difference_type	count;
	std::iterator_traits<std::list<VIterator>::iterator>::difference_type	step;

	count = std::distance(first,last);
	while (count > 0)
	{
		it = first; step=count/2; std::advance (it,step);
		if (!compare(val, *it))
		{
			this->comparisons++;
			first = ++it;
			count -= step + 1;
		}
		else
			count = step;
	}
	return first;
}
//////////

std::string	prefix( int n )
{
	std::string prefix = ""; 
	std::ostringstream oss;
	for (int i = 1; i < n; i++)
		oss << "  ";
	if (n < 10)
	{
		oss << "0";
	}
	oss << n;
	for (int i = 0; i < n; i++)
		oss << "  ";
	return prefix + oss.str();
}

// Merge Insertion Sort functions:

void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	comparisons = 0;
	static std::string indent = "";
	static int	lvl = 0;
	lvl++;
	std::cout << prefix(lvl) << "IN >>" << std::endl;

	printVIterator(first, last, BLOCKS);
	size_t	size = last - first;
	std::cout << prefix(lvl) << "size = " << size << std::endl;
	if (size < 2)
		return ;

	bool		oddSize = size % 2 != 0;
	VIterator	end = oddSize ? last - 1 : last;
	VIterator	start = first;

	std::cout << prefix(lvl) << "-Pairing" << std::endl;
	makePairs(start, end, comparisons);
	printVIterator(start, end, BLOCKS);

	indent += "  ";
	mergeInsertionSort(VIterator(first, first.size() * 2), VIterator(end, end.size() * 2));

	lvl--;
	std::cout << prefix(lvl) << "<< OUT" << std::endl;

	printVIterator(start, end, BLOCKS);

	// Now the current vector will be divided into two vectors
	// a1, a2, a3, ..., aN will be the highest values from every pair
	// b1, b2, b3, ..., bN will be the lowest values from every pair

	// Now we know that for every N in b, bN < aN

	// We can keep track of the positions of the elements in the aN chain by
	// using an std::list<VIterator> mainChain

	std::list<VIterator>	mainChain;
	// mainChain.push_front(start);
	// mainChain.push_front(start + 1);
	mainChain.push_back(start);
	mainChain.push_back(start + 1);
	// n[log2(3n/4)] - [2^[log2(6n)]/3] + [log2(6n)/2]

	// And we want to keep track of the positions at which we must insert the bN elements
	// So we can use an std::vector<std::list<VIterator>::iterator> pend

	std::vector<std::list<VIterator>::iterator>	pend;
	pend.reserve((size + 1) / 2 - 1);
	// However, pend stands for pending elements, so it's not the best name for it
	// A better name could be insertionPoints

	// Now, we will push into the mainChain, the aN elements
	// And we will push into the insertionPoints, the positions at which those elements were inserted

	for (VIterator it = start + 2; it != end; it += 2)
	{
		// std::cout << "INSERTING " << *(it + 1) << std::endl;
		// std::list<VIterator>::iterator tmp = mainChain.insert(mainChain.end(), it);
		std::list<VIterator>::iterator tmp = mainChain.insert(mainChain.end(), it + 1);
		pend.push_back(tmp);
	}

	if (oddSize)
	{
		pend.push_back(mainChain.end());
	}
	std::cout << prefix(lvl) << "Initial mainChain: " << std::endl;
	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << **it << " ";
	std::cout << std::endl;

	// std::cout << prefix(lvl) << "mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	// Now we will do the binary insertion part
	std::cout << prefix(lvl) << "Insertion" << std::endl;

	VIterator	current = start + 2; // Becuase we already inserted the first two elements
	std::vector<std::list<VIterator>::iterator>::iterator	current_pend = pend.begin();
	for (size_t k = 0; ; ++k)
	{
		long	dist = jacobsthalDiff[k];
		if (dist > std::distance(current_pend, pend.end()))
			break ;

		VIterator	it = current + dist * 2;
		typename std::vector<typename std::list<VIterator>::iterator>::iterator	pe = current_pend + dist;

		while (current_pend != pe)
		{
			--pe;
			it -= 2;
			std::list<VIterator>::iterator insertion_point = my_upper_bound(
				mainChain.begin(), *pe, *it);
			std::cout << "Inserting " << *it << " at " << **insertion_point << std::endl;
			mainChain.insert(insertion_point, it);
		}

		std::advance(current, dist * 2);
		std::advance(current_pend, dist);
	}

	// std::cout << prefix(lvl) << "mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	// After the binary insertion part, we must insert the remaining elements
	// std::cout << prefix(lvl) << "Insert" << std::endl;
	while (current_pend != pend.end())
	{
		std::list<VIterator>::iterator insertionPoint = my_upper_bound(
			mainChain.begin(), *current_pend, *current);
		std::cout << "INSERTING " << *current << std::endl;
		mainChain.insert(insertionPoint, current);
		current += 2;
		current_pend++;
	}

	std::cout << prefix(lvl) << "mainChain: ";
	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << **it << " ";
	std::cout << std::endl;

	// std::cout << prefix(lvl) << "Passing the mainChain to the original vector" << std::endl;

	std::vector<unsigned int>	cache;
	cache.reserve(size);

	// std::cout << prefix(lvl) << "Storing cache" << std::endl;
	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	{
		std::vector<unsigned int>::iterator begin = it->base();
		std::vector<unsigned int>::iterator end = begin + it->size();
		while (begin != end)
			cache.push_back(*begin++);
	}

	// std::cout << prefix(lvl) << "Vector before swap_ranges for cache:" << std::endl;
	// printVIterator(start, last, BLOCKS);
	std::swap_ranges(cache.begin(), cache.end(), start.base());

	// std::cout << prefix(lvl) << "Full resulting vector: ";
	// for (std::vector<unsigned int>::iterator it = cache.begin(); it != cache.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	printVIterator(start, last, BLOCKS);
}

void	pprintVector( std::vector<unsigned int> & vec )
{
	std::stringstream ss;
	ss << "Vector: ";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		ss << *it << " ";
	std::cout << ss.str() << std::endl;
}

void	mergeVIteratorToVector( VIterator start, VIterator end, std::vector<unsigned int> & vec )
{
	std::vector<unsigned int>	cache;
	cache.reserve(vec.size());
	for (VIterator it = start; it != end; it++)
	{
		std::vector<unsigned int>::iterator begin = it.base();
		std::vector<unsigned int>::iterator end = begin + it.size();
		while (begin != end)
			cache.push_back(*begin++);
	}
	std::swap_ranges(cache.begin(), cache.end(), vec.begin());
}

void	mergeVIteratorToVector( VIterator start, VIterator end, std::vector<unsigned int>::iterator vstart )
{
	std::vector<unsigned int>	cache;
	cache.reserve(start - end);
	for (VIterator it = start; it != end; it++)
	{
		std::vector<unsigned int>::iterator begin = it.base();
		std::vector<unsigned int>::iterator end = begin + it.size();
		while (begin != end)
			cache.push_back(*begin++);
	}
	std::swap_ranges(cache.begin(), cache.end(), vstart);
}

// Merge Insertion Sort for std::vector<unsigned int> // PUBLIC
void	PmergeMe::mergeInsertionSort( std::vector<unsigned int> & vec )
{
	VIterator start(vec.begin());
	VIterator end(vec.end());
	mergeInsertionSort(start, end);
	mergeVIteratorToVector(start, end, vec);
	std::cout << "Comparisons: " << comparisons << std::endl;
	comparisons = 0;
}

void	PmergeMe::mergeInsertionSort( std::vector<unsigned int>::iterator & first, std::vector<unsigned int>::iterator & last )
{
	VIterator start(first);
	VIterator end(last);
	mergeInsertionSort(start, end);
	mergeVIteratorToVector(start, end, first);
}

// // Merge Insertion Sort for std::vector<unsigned int> // PUBLIC
// void	PmergeMe::mergeInsertionSort( std::vector<unsigned int> & vec, bool (*compare)(unsigned int, unsigned int) )
// {
// 	VIterator start(vec.begin());
// 	VIterator end(vec.end());
// 	mergeInsertionSort(start, end, compare);
// 	std::vector<unsigned int>	cache;
// 	cache.reserve(vec.size());
// 	for (VIterator it = start; it != end; it++)
// 	{
// 		std::vector<unsigned int>::iterator begin = it.base();
// 		std::vector<unsigned int>::iterator end = begin + it.size();
// 		while (begin != end)
// 			cache.push_back(*begin++);
// 	}
// 	std::swap_ranges(cache.begin(), cache.end(), vec.begin());

// 	std::cout << "Final vector: ";
// 	pprintVector(vec);
// 	std::cout << std::endl;
// }

// void	PmergeMe::mergeInsertionSort( std::vector<unsigned int>::iterator & first, std::vector<unsigned int>::iterator & last, bool (*compare)(unsigned int, unsigned int) )
// {
// 	VIterator start(first);
// 	VIterator end(last);
// 	mergeInsertionSort(start, end, compareFunc);
// }


// void	PmergeMe::mergeInsertionSort( std::list<unsigned int> & lst )
// {
// 	LIterator start(lst.begin());
// 	LIterator end(lst.end());
// 	mergeInsertionSort(start, end);
// }
