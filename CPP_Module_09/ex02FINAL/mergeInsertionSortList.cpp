#include "PmergeMe.hpp"

typedef unsigned int uint_t;

void	PmergeMe::swapLIterator( LIterator<uint_t> lhs, LIterator<uint_t> rhs )
{
	LIterator<uint_t>::iterator_type	lhsEnd = lhs.base();
	advance(lhsEnd, lhs.size());
	std::swap_ranges(lhs.base(), lhsEnd, rhs.base());
	// std::swap_ranges(lhs.base(), this->next(lhs.base(), lhs.size()), rhs.base());
}

void	PmergeMe::sortAdjacentPairs( LIterator<uint_t> start, LIterator<uint_t> end )
{
	for (LIterator<uint_t> it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapLIterator(it, it + 1);
	}
}

void	PmergeMe::initialiseChain( std::list<LIterator<uint_t> > & chain, std::list<std::list<LIterator<uint_t> >::iterator> & chainPositions, LIterator<uint_t> start, LIterator<uint_t> end, bool isSizeOdd )
{
	chain.push_back(start); // a1
	chain.push_back(start + 1); // b1
	for (LIterator<uint_t> it = start + 2; it != end; it += 2)
	{
		std::list<LIterator<uint_t> >::iterator position = chain.insert(chain.end(), it + 1);
		chainPositions.push_back(position);
		// std::cout << "INSERTL-ChainPositions: " << **position << std::endl;
		// std::cout << "INSERTL-ChainL " << *(it + 1) << std::endl;
	}
	if (isSizeOdd)
		chainPositions.push_back(chain.end());
}

std::list<LIterator<uint_t> >::iterator	PmergeMe::binarySearch( std::list<LIterator<uint_t> >::iterator left, std::list<LIterator<uint_t> >::iterator right, unsigned int val )
{
	// std::cout << "Binary search" << std::endl;
	std::list<LIterator<uint_t> >::iterator	mid;
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

void	PmergeMe::insertElements( std::list<LIterator<uint_t> > & chain,
								  std::list<std::list<LIterator<uint_t> >::iterator> & chainPositions,
								  LIterator<uint_t> current )
{
	// // print chain
	// std::cout << "Chain: " << std::endl;
	// for (std::list<LIterator<uint_t> >::iterator it = chain.begin(); it != chain.end(); it++)
	// {
	// 	std::cout << **it << " ";
	// 	// std::cout << "Chain element: ";
	// 	// printLIterator(*it, *it + it->size());
	// }
	// std::cout << std::endl;
	// // print chain positions
	// std::cout << "Chain positions: ";
	// for (std::list<std::list<LIterator<uint_t> >::iterator>::iterator it = chainPositions.begin(); it != chainPositions.end(); it++)
	// {
	// 	std::cout << ***it << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "Inserting elements" << std::endl;
	// std::list<std::list<LIterator<uint_t> >::iterator>::iterator	chainPosNext = chainPositions.begin();
	LIterator<std::list<LIterator<uint_t> >::iterator> chainPosNext(chainPositions.begin());
	size_t	k = 3;
	while (true)
	{
		long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
		if (distToNextChainPos > std::distance(chainPosNext.base(), chainPositions.end()))
			break ;
		// std::cout << "LE " << distToNextChainPos << ", " << std::distance(chainPosNext.base(), chainPositions.end()) << std::endl;
		
		LIterator<uint_t>	it = current + distToNextChainPos * 2;
		LIterator<std::list<LIterator<uint_t> >::iterator>	chainPosIt = chainPosNext + distToNextChainPos;

		while (chainPosNext != chainPosIt)
		{
			--chainPosIt;
			it -= 2;
			std::list<LIterator<uint_t> >::iterator position = binarySearch(chain.begin(), *chainPosIt, *it);
			std::cout << "Inserting element " << *it << " at position " << **position << std::endl;
			if (position == chain.end())
				std::cout << " at the end" << std::endl;
			else
				std::cout << " at position " << **position << std::endl;
			chain.insert(position, it);
		}

		std::advance(current, distToNextChainPos * 2);
		std::advance(chainPosNext, distToNextChainPos);
		k++;
	}
	while (chainPosNext != chainPositions.end())
	{
		std::list<LIterator<uint_t> >::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
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

void	PmergeMe::passChainToIterator( std::list<LIterator<uint_t> > chain, LIterator<uint_t> start, LIterator<uint_t> last )
{
	LIterator<uint_t>::container_type	cache;
	last.base(); // To avoid unused variable warning
	for (std::list<LIterator<uint_t> >::iterator it = chain.begin(); it != chain.end(); it++)
	{
		LIterator<uint_t>::iterator_type	begin = it->base();
		LIterator<uint_t>::iterator_type	end = begin;
		std::advance(end, it->size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	PmergeMe::mergeInsertionSort( LIterator<uint_t> first, LIterator<uint_t> last )
{
	// std::cout << "RECURSSION IN -------------" << std::endl;
	size_t		size = std::distance(first.base(), last.base()) / first.size();
	if (size < 2)
		return ;
	bool		isSizeOdd = size % 2 != 0;
	LIterator<uint_t>	end = isSizeOdd ? last - 1 : last;
	LIterator<uint_t>&	start = first;
	// std::cout << "Before pair sort" << std::endl;
	// printLIterator(start, end);
	sortAdjacentPairs(start, end);
	// std::cout << "After pair sort" << std::endl;
	// printLIterator(start, end);

	if (size >= 4)
		mergeInsertionSort(LIterator<uint_t> (first, first.size() * 2), LIterator<uint_t> (end, end.size() * 2));

	std::list<LIterator<uint_t> >						chain;
	std::list<std::list<LIterator<uint_t> >::iterator>	chainPos;
	initialiseChain(chain, chainPos, start, end, isSizeOdd);

	insertElements(chain, chainPos, start + 2);

	passChainToIterator(chain, start, last);
	// printLIterator(start, last);
	// std::cout << "RECURSSION OUT -------------" << std::endl;
}
