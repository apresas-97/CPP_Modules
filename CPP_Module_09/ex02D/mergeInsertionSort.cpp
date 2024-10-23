#include "PmergeMe.hpp"

void	PmergeMe::sortAdjacentPairs( VIterator start, VIterator end )
{
	for (VIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapVIterator(it, it + 1);
	}
}

void	PmergeMe::sortAdjacentPairs( LIterator start, LIterator end )
{
	for (LIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapLIterator(it, it + 1);
	}
}

bool	PmergeMe::isSorted( VIterator first, VIterator last )
{
	for (VIterator it = first; it != last - 1; it++)
		if (it[0] > it[1])
			return false;
	return true;
}

bool	PmergeMe::isSorted( LIterator first, LIterator last )
{
	for (LIterator it = first; it != last - 1; it++)
		if (it[0] > it[1])
			return false;
	return true;
}

void	PmergeMe::passChainToIterator( std::list<VIterator> chain, VIterator start, VIterator last )
{
	std::vector<unsigned int>	cache;
	cache.reserve(last - start);
	for (std::list<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		std::vector<unsigned int>::iterator begin = it->base();
		std::vector<unsigned int>::iterator end = begin;
		std::advance(end, it->size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	PmergeMe::passChainToIterator( std::list<LIterator> chain, LIterator start, LIterator last )
{
	std::list<unsigned int>	cache;
	last.base();
	for (std::list<LIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		std::list<unsigned int>::iterator begin = it->base();
		std::list<unsigned int>::iterator end = begin;
		std::advance(end, it->size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

// Merge Insertion Sort for VIterator // PRIVATE
void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	if (isSorted(first, last))
		return ;
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

	passChainToIterator(chain, start, last);
	// std::vector<unsigned int>	cache;
	// cache.reserve(size);
	// for (std::list<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	// {
	// 	std::vector<unsigned int>::iterator begin = it->base();
	// 	std::vector<unsigned int>::iterator end = begin + it->size();
	// 	while (begin != end)
	// 	{
	// 		cache.push_back(*begin);
	// 		begin++;
	// 	}
	// }
	// std::swap_ranges(cache.begin(), cache.end(), start.base());
}

// Merge Insertion Sort for LIterator // PRIVATE
void	PmergeMe::mergeInsertionSort( LIterator first, LIterator last )
{
	if (isSorted(first, last))
		return ;
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

	// Initialise chain and chainPos
	for (LIterator it = start + 2; it != end; it += 2)
	{
		std::list<LIterator>::iterator position = chain.insert(chain.end(), it + 1);
		chainPos.push_back(position);
	}
	//

	// Insert elements until the last suitable jacobsthal number
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
	//

	// Insert remaining elements
	if (isSizeOdd)
		chainPos.push_back(chain.end());
	while (chainPosNext != chainPos.end())
	{
		std::list<LIterator>::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
		chain.insert(position, current);
		current += 2;
		chainPosNext++;
	}
	//

	passChainToIterator(chain, start, last);
	// LIterator::container_type	cache = passToCache<LIterator::container_type>(chain);
	// std::swap_ranges(cache.begin(), cache.end(), start.base());
}

// Merge Insertion Sort for std::vector<unsigned int> // PUBLIC
void	PmergeMe::mergeInsertionSort( std::vector<unsigned int> & vec )
{
	// this->_timeElapsed[VECTOR] = 0.0;
	// if (vec.size() < 2)
	// 	return ;
	// this->_elementsCount[VECTOR] = vec.size();

	// std::clock_t	timeStart = std::clock();
	// VIterator		start(vec.begin());
	// VIterator		end(vec.end());
	// mergeInsertionSort(start, end);
	// mergeVIteratorToVector(start, end, vec);
	// this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
	mergeInsertionSort(vec.begin(), vec.end());
}

// Merge Insertion Sort for std::vector iterator range // PUBLIC
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
	mergeIteratorToContainer(start, end, first);
	this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

// Merge Insertion Sort for std::list
void	PmergeMe::mergeInsertionSort( std::list<unsigned int> & lst )
{
	// this->_timeElapsed[LIST] = 0.0;
	// if (lst.size() < 2)
	// 	return ;
	// this->_elementsCount[LIST] = lst.size();

	// std::clock_t	timeStart = std::clock();
	// LIterator		start(lst.begin());
	// LIterator		end(lst.end());
	// mergeInsertionSort(start, end);
	// mergeLIteratorToList(start, end, lst);
	// this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
	mergeInsertionSort(lst.begin(), lst.end());
}

// Merge Insertion Sort for std::list iterator range // PUBLIC
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
	mergeIteratorToContainer(start, end, first);
	this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}
