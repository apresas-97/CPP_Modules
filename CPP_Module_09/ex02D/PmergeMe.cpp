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
bool	compare( const int & lhs, const VIterator & rhs )
{
	return lhs < *rhs;
}


// Merge Insertion Sort functions:

void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	static int stopper = 0;
	stopper++;
	if (stopper >= 5)
		return ;

	std::cout << "Iteration start" << std::endl;

	size_t	size = last - first;
	if (size < 2)
		return ;
	std::cout << "size = " << size << std::endl;
	printVIterator(first, last);
	
	bool		oddSize = size % 2 != 0;
	VIterator	end = oddSize ? last - 1 : last;
	VIterator	start = first;

	makePairs(start, end);

	// std::cout << "Vector: ";
	// printVIterator(start, end);

	mergeInsertionSort(VIterator(first, first.size() * 2), VIterator(end, end.size() * 2));
	std::cout << "Iteration continue" << std::endl;

	// std::cout << "Vector: ";
	// printVIterator(start, end);
	// if (oddSize)
	// {
	// 	std::cout << "Left over: ";
	// 	printVIterator(end, last);
	// }

	// Now the current vector will be divided into two vectors
	// a1, a2, a3, ..., aN will be the highest values from every pair
	// b1, b2, b3, ..., bN will be the lowest values from every pair

	// Now we know that for every N in b, bN < aN

	// We can keep track of the positions of the elements in the aN chain by
	// using an std::list<VIterator> mainChain

	std::list<VIterator>	mainChain;
	mainChain.push_front(start);
	mainChain.push_front(start + 1);

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
		std::list<VIterator>::iterator tmp = mainChain.insert(mainChain.end(), it + 1);
		pend.push_back(tmp);
	}

	if (oddSize)
	{
		pend.push_back(mainChain.end());
	}

	// std::cout << "mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	// Now we will do the binary insertion part
	std::cout << "Binary insertion" << std::endl;

	VIterator	current = start + 2; // Becuase we already inserted the first two elements
	std::vector<std::list<VIterator>::iterator>::iterator	current_pend = pend.begin();
	for (size_t k = 0; ; ++k)
	{
		long	dist = jacobsthalDiff[k];
		if (dist > std::distance(current_pend, pend.end()))
			break ;

		VIterator	it = current + dist * 2;
		typename std::vector<typename std::list<VIterator>::iterator>::iterator	pe = current_pend + dist;

		do
		{
			--pe;
			// std::list<VIterator>::iterator insertion_point = mainChain.begin();
			// while (insertion_point != mainChain.end() && **pe < it)
			// 	insertion_point++;

			std::list<VIterator>::iterator insertion_point = std::upper_bound(
				mainChain.begin(), *pe, *it, compare);

			mainChain.insert(insertion_point, it);
		} while (current_pend != pe);

		std::advance(current, dist * 2);
		std::advance(current_pend, dist);
	}

	std::cout << "mainChain: ";
	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << **it << " ";
	std::cout << std::endl;

	// After the binary insertion part, we must insert the remaining elements
	std::cout << "Inserting remaining elements" << std::endl;
	while (current_pend != pend.end())
	{
		std::list<VIterator>::iterator insertionPoint = std::upper_bound(
			mainChain.begin(), *current_pend, *current, compare);
		mainChain.insert(insertionPoint, current);
		current += 2;
		current_pend++;
	}

	// std::cout << "final mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	std::cout << "Passing the mainChain to the original vector" << std::endl;

	std::vector<int>	cache;
	cache.reserve(size);

	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	{
		std::vector<int>::iterator begin = it->base();
		std::vector<int>::iterator end = begin + it->size();
		while (begin != end)
			cache.push_back(*begin++);
	}

	std::swap_ranges(cache.begin(), cache.end(), start.base());

	std::cout << "Full resulting vector: ";
	for (std::vector<int>::iterator it = cache.begin(); it != cache.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Resulting vector: ";
	printVIterator(start, last);
}

// Merge Insertion Sort for std::vector<int> // PUBLIC
void	PmergeMe::mergeInsertionSort( std::vector<int> & vec )
{
	VIterator start(vec.begin());
	VIterator end(vec.end());
	mergeInsertionSort(start, end);
}

// void	PmergeMe::mergeInsertionSort( std::list<int> & lst )
// {
// 	LIterator start(lst.begin());
// 	LIterator end(lst.end());
// 	mergeInsertionSort(start, end);
// }
