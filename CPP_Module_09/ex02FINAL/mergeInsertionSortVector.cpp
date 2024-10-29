#include "PmergeMe.hpp"

///
void	printChain( std::vector<VIterator> & chain )
{
	for (std::vector<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		if (it != chain.end())
        {
            std::cout << **it << std::endl;
        }
        else
        {
            std::cout << "Invalid iterator in chain" << std::endl;
        }
	}
	std::cout << std::endl;
}

void	printChainPos( std::vector<std::vector<VIterator>::iterator> & chainPos, std::vector<VIterator> & chain )
{
	for (std::vector<std::vector<VIterator>::iterator>::iterator it = chainPos.begin(); it != chainPos.end(); it++)
	{
		if (it != chainPos.end() && *it != chain.end())
        {
            std::cout << **(*it) << std::endl;
        }
        else if (*it == chain.end())
		{
			std::cout << "Chain end iterator" << std::endl;
		}
		else
        {
            std::cout << "Invalid iterator in chainPos" << std::endl;
        }
	}
	std::cout << std::endl;
}
/////////////////////////////////


void	PmergeMe::swapVIterator( VIterator lhs, VIterator rhs )
{
	VIterator::iterator_type	lhsEnd = lhs.base();
	advance(lhsEnd, lhs.size());
	std::swap_ranges(lhs.base(), lhsEnd, rhs.base());
	// std::swap_ranges(lhs.base(), this->next(lhs.base(), lhs.size()), rhs.base());
}

void	PmergeMe::sortAdjacentPairs( VIterator start, VIterator end )
{
	for (VIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapVIterator(it, it + 1);
	}
}

void	PmergeMe::initialiseChain( std::vector<VIterator> & chain, std::vector<std::vector<VIterator>::iterator> & chainPositions, VIterator start, VIterator end, size_t size, bool isSizeOdd )
{
	std::cout << "Initialise Chains" << std::endl;
	// std::cout << "Size: " << size << std::endl;
	chain.reserve(size);
	chain.push_back(start); // a1
	chain.push_back(start + 1); // b1
	chainPositions.reserve((size + 1) / 2 - 1);
	// std::cout << "Reserved memory: " << (size + 1) / 2 - 1 << std::endl;
	// std::cout << "VECTOR INITIALISE CHAIN" << std::endl;
	// size_t	i = 0;
	// size_t	k = 2;
	for (VIterator it = start + 2; it != end; it += 2)
	{
		std::vector<VIterator>::iterator position = chain.insert(chain.end(), it + 1);
		chainPositions.push_back(position);
		// std::cout << *chain[k] << std::endl;
		// std::cout << "INSERTV-ChainPositions: " << **position << std::endl;
		// std::cout << "INSERTV-ChainL " << *(it + 1) << std::endl;
		// chainIndex[i] = k;
		// k++;
	}
	std::cout << "isSizeOdd = " << isSizeOdd << std::endl;
	if (isSizeOdd)
		chainPositions.push_back(chain.end());
	// std::cout << "chainPositions.size = " << chainPositions.size() << std::endl;
}

std::vector<VIterator>::iterator	PmergeMe::binarySearch( std::vector<VIterator>::iterator left, std::vector<VIterator>::iterator right, unsigned int val )
{
	// std::cout << "Binary search" << std::endl;
	std::vector<VIterator>::iterator	mid;
	std::ptrdiff_t			search_range;
	std::ptrdiff_t			half_range;

	search_range = std::distance(left, right);
	while (search_range > 0)
	{
		mid = left;
		half_range = search_range / 2;
		std::advance (mid, half_range);
		// std::cout << "Comparing " << val << " with " << *(*mid) << std::endl;
		if (!(val < *(*mid)))
		{
			mid++;
			left = mid;
			search_range -= half_range + 1;
		}
		else
			search_range = half_range;
	}
	// if (left == right)
	// 	std::cout << "Returning end" << std::endl;
	// else
	// 	std::cout << "Returning " << **left << std::endl;
	return left;
}

// std::vector<VIterator>::iterator	PmergeMe::binarySearch( std::vector<VIterator>::iterator left, size_t right, unsigned int val )
// {
// 	// std::cout << "Binary search" << std::endl;
// 	std::vector<VIterator>::iterator	mid;
// 	std::ptrdiff_t			search_range;
// 	std::ptrdiff_t			half_range;
// 	size_t					ll = 0;

// 	search_range = right - ll;
// 	while (search_range > 0)
// 	{
// 		mid = left;
// 		half_range = search_range / 2;
// 		std::advance (mid, half_range);
// 		// std::cout << "Comparing " << val << " with " << *(*mid) << std::endl;
// 		if (!(val < *(*mid)))
// 		{
// 			mid++;
// 			left = mid;
// 			search_range -= half_range + 1;
// 		}
// 		else
// 			search_range = half_range;
// 	}
// 	// if (left == right)
// 	// 	std::cout << "Returning end" << std::endl;
// 	// else
// 	// 	std::cout << "Returning " << **left << std::endl;
// 	return left;
// }

void	updateChainPos( std::vector<std::vector<VIterator>::iterator> & chainPos, VIterator it )
{
	std::vector<std::vector<VIterator>::iterator>::iterator chainPosIt = chainPos.begin();
	for (; chainPosIt != chainPos.end(); chainPosIt++)
	{
		if (**(*chainPosIt) > *it)
			break ;
	}
	std::cout << "Changes expected after " << **(*chainPosIt) << std::endl;
}

void	PmergeMe::insertElements( std::vector<VIterator> & chain,
								  std::vector<std::vector<VIterator>::iterator> & chainPositions,
								  VIterator current )
{
	// // print chain
	// std::cout << "Chain: " << std::endl;
	// for (std::vector<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	// {
	// 	std::cout << **it << " ";
	// 	// std::cout << "Chain element: ";
	// 	// printLIterator(*it, *it + it->size());
	// }
	// std::cout << std::endl;
	// // print chain positions
	// std::cout << "Chain positions: ";
	// for (std::vector<std::vector<VIterator>::iterator>::iterator it = chainPositions.begin(); it != chainPositions.end(); it++)
	// {
	// 	std::cout << ***it << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "Inserting elements" << std::endl;
	std::vector<std::vector<VIterator>::iterator>::iterator	chainPosNext = chainPositions.begin();
	size_t	k = 3;
	while (true)
	{
		long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
		if (distToNextChainPos > std::distance(chainPosNext, chainPositions.end()))
			break ;
		// std::cout << "VE " << distToNextChainPos << ", " << std::distance(chainPosNext, chainPositions.end()) << std::endl;	
		
		VIterator	it = current + distToNextChainPos * 2;
		std::vector<std::vector<VIterator>::iterator>::iterator	chainPosIt = chainPosNext + distToNextChainPos;

		while (chainPosNext != chainPosIt)
		{
			--chainPosIt;
			it -= 2;
			std::vector<VIterator>::iterator position = binarySearch(chain.begin(), *chainPosIt, *it);
			std::cout << "Inserting element " << *it << " at position " << **position << std::endl;
			if (position == chain.end())
				std::cout << " at the end" << std::endl;
			else
				std::cout << " at position " << **position << std::endl;
			chain.insert(position, it);
			// update chainPos to compensate for the insertion
			updateChainPos(chainPositions, it);
			std::cout << "AEA" << std::endl;
			printChainPos(chainPositions, chain);
		}

		std::advance(current, distToNextChainPos * 2);
		std::advance(chainPosNext, distToNextChainPos);
		k++;
	}

	std::cout << "Printing current chain" << std::endl;
	printChain(chain);
	std::cout << "Printing current chain positions" << std::endl;
	printChainPos(chainPositions, chain);

	while (chainPosNext != chainPositions.end())
	{
		std::vector<VIterator>::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
		std::cout << "Inserting element " << *current << std::endl;
		if (position == chain.end())
			std::cout << " at the end" << std::endl;
		else
			std::cout << " at position " << **position << std::endl;
		chain.insert(position, current);
		current += 2;
		chainPosNext++;
	}
}

void	PmergeMe::passChainToIterator( std::vector<VIterator> chain, VIterator start, VIterator last )
{
	VIterator::container_type	cache;
	cache.reserve(last - start);
	for (std::vector<VIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		VIterator::iterator_type	begin = it->base();
		VIterator::iterator_type	end = begin;
		std::advance(end, it->size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	std::cout << "Recurssion IN--------------------------" << std::endl;
	size_t		size = std::distance(first.base(), last.base()) / first.size();
	if (size < 2)
		return ;
	bool		isSizeOdd = size % 2 != 0;
	VIterator	end = isSizeOdd ? last - 1 : last;
	VIterator&	start = first;
	std::cout << "Before pair sort" << std::endl;
	printVIterator(first, last);
	sortAdjacentPairs(start, end);
	std::cout << "After pair sort" << std::endl;
	printVIterator(first, last);

	if (size >= 4)
		mergeInsertionSort(VIterator(first, first.size() * 2), VIterator(end, end.size() * 2));
	std::cout << "Recurssion continues--------" << std::endl;
	std::vector<VIterator>							chain;
	std::vector<std::vector<VIterator>::iterator>	chainPos;
	initialiseChain(chain, chainPos, start, end, size, isSizeOdd);

	std::cout << "Chain INITIALISED to:" << std::endl;
	printChain(chain);
	std::cout << "ChainPos INITIALISED to:" << std::endl;
	printChainPos(chainPos, chain);

	// std::cout << "Before insert elements" << std::endl;
	// printVIterator(start, end);
	insertElements(chain, chainPos, start + 2);

	passChainToIterator(chain, start, last);
	// std::cout << "After insert elements" << std::endl;
	// printVIterator(start, last);
	std::cout << "Recurssion OUT--------------------" << std::endl;
}
