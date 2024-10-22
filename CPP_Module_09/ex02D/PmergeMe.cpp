#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[VECTOR] = 0;
	this->_elementsCount[LIST] = 0;
	initJacobsthalNumbers();
}

PmergeMe::PmergeMe( PmergeMe const &other ) { *this = other; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other ) { }
	return *this;
}

void	PmergeMe::initJacobsthalNumbers( void )
{
	this->_jacobsthalNumbers[0] = 0;
	this->_jacobsthalNumbers[1] = 1;
	for (size_t i = 2; i < 63; i++)
		this->_jacobsthalNumbers[i] = this->_jacobsthalNumbers[i - 1] + 2 * this->_jacobsthalNumbers[i - 2];
}

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

// Sorts the pairs of elements in the range [start, end)
void	PmergeMe::sortAdjacentPairs( VIterator start, VIterator end )
{
	for (VIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1]) // Make sure this is really correct
			swapVIterator(it, it + 1);
	}
}

void	PmergeMe::sortAdjacentPairs( LIterator start, LIterator end )
{
	for (LIterator it = start; it != end; it += 2)
	{
		if (it + 1 == end)
			break ;
		if (it[0] > it[1]) // Make sure this is really correct
			swapLIterator(it, it + 1);
	}
}

// Merge Insertion Sort functions:
void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	size_t		size = last - first;
	if (size < 2)
		return ;
	bool		isSizeOdd = size % 2 != 0;
	VIterator	end = isSizeOdd ? last - 1 : last;
	VIterator&	start = first;

	sortAdjacentPairs(start, end);
	mergeInsertionSort(VIterator(first, first.size() * 2), VIterator(end, end.size() * 2));

	std::list<VIterator>	chain;
	chain.push_back(start); // a1
	chain.push_back(start + 1); // b1

	std::vector<std::list<VIterator>::iterator>	chainPos;
	chainPos.reserve((size + 1) / 2 - 1);

	for (VIterator it = start + 2; it != end; it += 2)
	{
		std::list<VIterator>::iterator position = chain.insert(chain.end(), it + 1);
		chainPos.push_back(position);
	}

	std::vector<std::list<VIterator>::iterator>::iterator	chainPosNext = chainPos.begin();
	VIterator	current = start + 2;
	size_t		k = 3;
	while (true)
	{
		long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
		if (distToNextChainPos > std::distance(chainPosNext, chainPos.end()))
			break ;

		VIterator	it = current + distToNextChainPos * 2;
		std::vector<std::list<VIterator>::iterator>::iterator	chainPosIt = chainPosNext + distToNextChainPos;

		while (chainPosNext != chainPosIt)
		{
			--chainPosIt;
			it -= 2;
			std::list<VIterator>::iterator position = binarySearch(chain.begin(), *chainPosIt, *it);
			chain.insert(position, it);
		}

		std::advance(current, distToNextChainPos * 2);
		std::advance(chainPosNext, distToNextChainPos);
		k++;
	}

	if (isSizeOdd)
		chainPos.push_back(chain.end());
	while (chainPosNext != chainPos.end())
	{
		std::list<VIterator>::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
		chain.insert(position, current);
		current += 2;
		chainPosNext++;
	}

	std::vector<unsigned int>	cache;
	cache.reserve(size);
	for (std::list<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
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
	this->_timeElapsed[VECTOR] = 0.0;
	if (vec.size() < 2)
		return ;
	this->_elementsCount[VECTOR] = vec.size();

	std::clock_t	timeStart = std::clock();
	VIterator		start(vec.begin());
	VIterator		end(vec.end());
	mergeInsertionSort(start, end);
	mergeVIteratorToVector(start, end, vec);
	this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

void	PmergeMe::mergeInsertionSort( std::vector<unsigned int>::iterator first, std::vector<unsigned int>::iterator last )
{
	this->_timeElapsed[VECTOR] = 0.0;
	if (std::distance(first, last) < 2)
		return ;
	this->_elementsCount[VECTOR] = std::distance(first, last);

	std::clock_t	timeStart = std::clock();
	VIterator		start(first);
	VIterator		end(last);
	mergeInsertionSort(start, end);
	mergeVIteratorToVector(start, end, first);
	this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


LIteratorList::iterator	PmergeMe::binarySearch(LIteratorList::iterator left, LIteratorList::iterator right, unsigned int val )
{
	LIteratorList::iterator											mid;
	std::iterator_traits<LIteratorList::iterator>::difference_type	search_range;
	std::iterator_traits<LIteratorList::iterator>::difference_type	half_range;

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

void	PmergeMe::mergeInsertionSort( LIterator first, LIterator last )
{
	size_t		size = std::distance(first.base(), last.base()) / first.size();
	if (size < 2)
		return ;
	bool		isSizeOdd = size % 2 != 0;
	LIterator	end = isSizeOdd ? last - 1 : last;
	LIterator&	start = first;

	sortAdjacentPairs(start, end);
	mergeInsertionSort(LIterator(first, first.size() * 2), LIterator(end, end.size() * 2));

	std::list<LIterator>	chain;
	chain.push_back(start); // a1
	chain.push_back(start + 1); // b1

	std::vector<std::list<LIterator>::iterator>	chainPos;
	chainPos.reserve((size + 1) / 2 - 1);

	for (LIterator it = start + 2; it != end; it += 2)
	{
		std::list<LIterator>::iterator position = chain.insert(chain.end(), it + 1);
		chainPos.push_back(position);
	}

	std::vector<std::list<LIterator>::iterator>::iterator	chainPosNext = chainPos.begin();
	LIterator	current = start + 2;
	size_t		k = 3;
	while (true)
	{
		long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
		if (distToNextChainPos > std::distance(chainPosNext, chainPos.end()))
			break ;
		
		LIterator	it = current + distToNextChainPos * 2;
		std::vector<std::list<LIterator>::iterator>::iterator	chainPosIt = chainPosNext + distToNextChainPos;

		while (chainPosNext != chainPosIt)
		{
			--chainPosIt;
			it -= 2;
			std::list<LIterator>::iterator position = binarySearch(chain.begin(), *chainPosIt, *it);
			chain.insert(position, it);
		}

		std::advance(current, distToNextChainPos * 2);
		std::advance(chainPosNext, distToNextChainPos);
		k++;
	}

	if (isSizeOdd)
		chainPos.push_back(chain.end());
	while (chainPosNext != chainPos.end())
	{
		std::list<LIterator>::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
		chain.insert(position, current);
		current += 2;
		chainPosNext++;
	}

	LIterator::container_type	cache = passToCache<LIterator::container_type>(chain);
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	mergeLIteratorToList( LIterator start, LIterator end, std::list<unsigned int> & lst )
{
	std::list<unsigned int>	cache;
	for (LIterator it = start; it != end; it++)
	{
		std::list<unsigned int>::iterator begin = it.base();
		std::list<unsigned int>::iterator end = begin;
		std::advance(end, it.size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), lst.begin());
}

void	mergeLIteratorToList( LIterator start, LIterator end, std::list<unsigned int>::iterator lstart )
{
	std::list<unsigned int>	cache;
	for (LIterator it = start; it != end; it++)
	{
		std::list<unsigned int>::iterator begin = it.base();
		std::list<unsigned int>::iterator end = begin;
		std::advance(end, it.size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), lstart);
}

void	PmergeMe::mergeInsertionSort( std::list<unsigned int>::iterator first, std::list<unsigned int>::iterator last )
{
	this->_timeElapsed[LIST] = 0.0;
	if (std::distance(first, last) < 2)
		return ;
	this->_elementsCount[LIST] = std::distance(first, last);

	std::clock_t	timeStart = std::clock();
	LIterator		start(first);
	LIterator		end(last);
	mergeInsertionSort(start, end);
	mergeLIteratorToList(start, end, first);
	this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

void	PmergeMe::mergeInsertionSort( std::list<unsigned int> & lst )
{
	this->_timeElapsed[LIST] = 0.0;
	if (lst.size() < 2)
		return ;
	this->_elementsCount[LIST] = lst.size();

	std::clock_t	timeStart = std::clock();
	LIterator		start(lst.begin());
	LIterator		end(lst.end());
	mergeInsertionSort(start, end);
	mergeLIteratorToList(start, end, lst);
	this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

void	PmergeMe::printTimeElapsed( void )
{
	std::cout << "Time to sort " << this->_elementsCount[VECTOR] << " elements with std::vector: ";
	if (this->_timeElapsed[VECTOR] * 1000 < 1)
		std::cout << this->_timeElapsed[VECTOR] * 1000000.0 << "us" << std::endl;
	else if (this->_timeElapsed[VECTOR] < 1)
		std::cout << this->_timeElapsed[VECTOR] * 1000.0 << "ms" << std::endl;
	else
		std::cout << this->_timeElapsed[VECTOR] << "s" << std::endl;
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = 0;

	std::cout << "Time to sort " << this->_elementsCount[LIST] << " elements with std::list: ";
	if (this->_timeElapsed[LIST] * 1000 < 1)
		std::cout << this->_timeElapsed[LIST] * 1000000.0 << "us" << std::endl;
	else if (this->_timeElapsed[LIST] < 1)
		std::cout << this->_timeElapsed[LIST] * 1000.0 << "ms" << std::endl;
	else
		std::cout << this->_timeElapsed[LIST] << "s" << std::endl;
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[LIST] = 0;
}
