#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	timeElapsed = 0.0;
	initJacobsthalNumbers();
	// initJacobsthalDiff();
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

// void	PmergeMe::initJacobsthalDiff( void )
// {
// 	jacobsthalDiff[0] = 2;
// 	jacobsthalDiff[1] = 2;
// 	for (size_t i = 2; i < 63; i++)
// 		jacobsthalDiff[i] = jacobsthalDiff[i - 1] + 2 * jacobsthalDiff[i - 2];
// }

VIteratorList::iterator	PmergeMe::binarySearch(VIteratorList::iterator left, VIteratorList::iterator right, unsigned int val )
{
	VIteratorList::iterator											mid;
	std::iterator_traits<VIteratorList::iterator>::difference_type	search_range;
	std::iterator_traits<VIteratorList::iterator>::difference_type	half_range;

	search_range = std::distance(left, right);
	while (search_range > 0)
	{
		mid = left;
		half_range = search_range / 2;
		std::advance (mid, half_range);
		if (!(val < **mid))
		{
			mid++;
			left = mid;
			search_range -= half_range + 1;
		}
		else
			search_range = half_range;
	}
	return left;
}

// DEBUG
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

void	initJacobsthalNumberss( size_t *jacobsthalNumbers )
{
	jacobsthalNumbers[0] = 0;
	jacobsthalNumbers[1] = 1;
	for (size_t i = 2; i < 63; i++)
		jacobsthalNumbers[i] = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
}

// Sorts the pairs of elements in the range [start, end)
void	PmergeMe::makePairs( VIterator start, VIterator end )
{
	for (VIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1]) // Make sure this is really correct
			swapVIterator(it, it + 1);
	}
}

// Merge Insertion Sort functions:
void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	timeElapsed = 0.0;
	std::clock_t	timeStart = std::clock();

	// static int	lvl = 0;
	// lvl++;
	// std::cout << prefix(lvl) << "IN >>" << std::endl;

	// printVIterator(first, last, BLOCKS);
	size_t	size = last - first;
	// std::cout << prefix(lvl) << "size = " << size << std::endl;
	if (size < 2)
		return ;

	bool		oddSize = size % 2 != 0;
	VIterator	end = oddSize ? last - 1 : last;
	VIterator&	start = first;

	// std::cout << prefix(lvl) << "-Pairing" << std::endl;
	makePairs(start, end);
	// printVIterator(start, end, BLOCKS);

	mergeInsertionSort(VIterator(first, first.size() * 2), VIterator(end, end.size() * 2));

	// lvl--;
	// std::cout << prefix(lvl) << "<< OUT" << std::endl;

	// printVIterator(start, end, BLOCKS);

	// Now the current vector will be divided into two vectors
	// a1, a2, a3, ..., aN will be the highest values from every pair
	// b1, b2, b3, ..., bN will be the lowest values from every pair

	// Now we know that for every N in b, bN < aN

	// We can keep track of the positions of the elements in the aN chain by
	// using an std::list<VIterator> mainChain

	std::list<VIterator>	mainChain;
	mainChain.push_back(start); // a1
	mainChain.push_back(start + 1); // b1

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
		// std::list<VIterator>::iterator tmp = mainChain.insert(mainChain.end(), it + 1);
		// pend.push_back(tmp);
		pend.push_back(mainChain.insert(mainChain.end(), it + 1));
	}

	// if (oddSize)
	// {
	// 	pend.push_back(mainChain.end());
	// }
	// std::cout << prefix(lvl) << "Initial mainChain: " << std::endl;
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		// std::cout << **it << " ";
	// std::cout << std::endl;

	// std::cout << prefix(lvl) << "mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	// Now we will do the binary insertion part
	// std::cout << prefix(lvl) << "Insertion" << std::endl;

	VIterator	current = start + 2;
	std::vector<std::list<VIterator>::iterator>::iterator	current_pend = pend.begin();
	size_t	k = 3;
	while (true)
	{
		long	dist = jacobsthalNumbers[k] - jacobsthalNumbers[k - 1];
		if (dist > std::distance(current_pend, pend.end()))
			break ;
		
		VIterator	it = current + dist * 2;
		std::vector<std::list<VIterator>::iterator>::iterator	pe = current_pend + dist;

		while (current_pend != pe)
		{
			--pe;
			it -= 2;
			// std::list<VIterator>::iterator insertionPoint = binarySearch(mainChain.begin(), *pe, *it);
			// mainChain.insert(insertionPoint, it);
			mainChain.insert(binarySearch(mainChain.begin(), *pe, *it), it);
		}

		std::advance(current, dist * 2);
		std::advance(current_pend, dist);
		k++;
	}

	// std::cout << prefix(lvl) << "mainChain: ";
	// for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	if (oddSize)
	{
		pend.push_back(mainChain.end());
	}

	// After the binary insertion part, we must insert the remaining elements
	// std::cout << prefix(lvl) << "Insertga" << std::endl;
	while (current_pend != pend.end())
	{
		// std::list<VIterator>::iterator insertionPoint = binarySearch(mainChain.begin(), *current_pend, *current);
		// mainChain.insert(insertionPoint, current);
		mainChain.insert(binarySearch(mainChain.begin(), *current_pend, *current), current);
		// std::advance(current, 2);
		// std::advance(current_pend, 1);
		current += 2;
		current_pend++;
	}

	std::vector<unsigned int>	cache;
	cache.reserve(size);

	// std::cout << prefix(lvl) << "making cache" << std::endl;
	for (std::list<VIterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	{
		std::vector<unsigned int>::iterator begin = it->base();
		std::vector<unsigned int>::iterator end = begin + it->size();
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());

	timeElapsed = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
	// std::cout << "OUT!" << std::endl;
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
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), vec.begin());
}

void	mergeVIteratorToVector( VIterator start, VIterator end, std::vector<unsigned int>::iterator vstart )
{
	std::vector<unsigned int>	cache;
	cache.reserve(end - start);
	for (VIterator it = start; it != end; it++)
	{
		std::vector<unsigned int>::iterator begin = it.base();
		std::vector<unsigned int>::iterator end = begin + it.size();
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
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
}

void	PmergeMe::mergeInsertionSort( std::vector<unsigned int>::iterator first, std::vector<unsigned int>::iterator last )
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

void	PmergeMe::printTimeElapsed( void )
{
	if (timeElapsed * 1000 < 1)
		std::cout << "Time elapsed: " << timeElapsed * 1000000.0 << "us" << std::endl;
	else if (timeElapsed < 1)
		std::cout << "Time elapsed: " << timeElapsed * 1000.0 << "ms" << std::endl;
	else
		std::cout << "Time elapsed: " << timeElapsed << "s" << std::endl;
}
