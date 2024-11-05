#include "PmergeMe.hpp"

void	PmergeMe::mergeInsertionSort( list & lst )
{
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[LIST] = lst.size();
	if (lst.size() < 2)
		return ;
	this->timeStart(LIST);

	LIterator	start(lst.begin());
	LIterator	end(lst.end());
	mergeInsertionSort(start, end);
	this->timeEnd(LIST);
}

static void	sortAdjacentPairs( LIterator start, LIterator end )
{
	for (LIterator it = start; it != end; it += 2)
	{
		// std::cout << "X" << std::endl;
		if (it[0] > it[1])
			swapLIterator(it, it + 1);
	}
}

static void	initialiseChain( std::list<LIterator> & mainchain, std::list<std::list<LIterator>::iterator> & mainchainPositions, LIterator start, LIterator end, bool isSizeOdd )
{
	mainchain.push_back(start);
	mainchain.push_back(start + 1);
	for (LIterator it = start + 2; it != end; it += 2)
	{
		std::list<LIterator>::iterator	position = mainchain.insert(mainchain.end(), it + 1);
		mainchainPositions.push_back(position);
	}
	if (isSizeOdd)
		mainchainPositions.push_back(mainchain.end()); // actually points to LIterator "last", the left out element
}

static std::list<LIterator>::iterator	binarySearch( std::list<LIterator>::iterator left, std::list<LIterator>::iterator right, unsigned int val )
{
	std::list<LIterator>::iterator	mid;
	std::ptrdiff_t					searchRange;
	std::ptrdiff_t					halfRange;

	searchRange = std::distance(left, right);
	while (searchRange > 0)
	{
		mid = left;
		halfRange = searchRange / 2;
		std::advance (mid, halfRange);
		// std::cout << "X" << std::endl;
		if (!(val < *(*mid)))
		{
			++mid;
			left = mid;
			searchRange -= halfRange + 1;
		}
		else
			searchRange = halfRange;
	}
	return left;
}

static void	insertElements(	std::list<LIterator> & mainchain,
							std::list<std::list<LIterator>::iterator> & chainPositions,
							LIterator bN )
{
	std::list<std::list<LIterator>::iterator>::iterator	aN = chainPositions.begin();
	size_t												k = 3;
	while (true)
	{
		long	distToNext = getJacobsthalNumber(k) - getJacobsthalNumber(k - 1);
		if (distToNext > std::distance(aN, chainPositions.end()))
			break ;

		LIterator											bIt = bN;
		std::list<std::list<LIterator>::iterator>::iterator	aIt = aN;
		std::advance(bIt, distToNext * 2);
		std::advance(aIt, distToNext);

		while (aIt != aN)
		{
			--aIt;
			bIt -= 2;
			std::list<LIterator>::iterator position = binarySearch(mainchain.begin(), *aIt, *bIt);
			mainchain.insert(position, bIt);
		}

		std::advance(bN, distToNext * 2);
		std::advance(aN, distToNext);
		++k;
	}
	while (aN != chainPositions.end())
	{
		std::list<LIterator>::iterator position = binarySearch(mainchain.begin(), *aN, *bN);
		mainchain.insert(position, bN);
		bN += 2;
		++aN;
	}
}

static void	passChainToIterator( std::list<LIterator> chain, LIterator start )
{
	LIterator::container_type	cache;
	for (std::list<LIterator>::iterator it = chain.begin(); it != chain.end(); ++it)
	{
		LIterator::iterator_type	begin = it->base();
		LIterator::iterator_type	end = it->end();
		while (begin != end)
		{
			cache.push_back(*begin);
			++begin;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	PmergeMe::mergeInsertionSort( LIterator first, LIterator last )
{
	size_t	size = std::distance(first, last);
	if (size < 2)
		return ;
	size_t		itSize = first.size();
	bool		isSizeOdd = size % 2 != 0;
	LIterator	end = isSizeOdd ? last - 1 : last;
	LIterator &	start = first;

	sortAdjacentPairs(start, end);

	if (size >= 4)
		mergeInsertionSort(LIterator(start, itSize * 2), LIterator(end, itSize * 2));
	if (size == 2)
		return ;

	std::list<LIterator>						mainchain;
	std::list<std::list<LIterator>::iterator>	mainchainPositions;
	initialiseChain(mainchain, mainchainPositions, start, end, isSizeOdd);

	insertElements(mainchain, mainchainPositions, start + 2);

	passChainToIterator(mainchain, start);
}