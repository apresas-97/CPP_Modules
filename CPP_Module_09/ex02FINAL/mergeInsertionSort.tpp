// #include "PmergeMe.hpp"

// template<class Iterator>
// void	PmergeMe::printIterator( Iterator start, Iterator end )
// {
// 	if (start.size() == 1)
// 	{
// 		for (Iterator it = start; it != end; it++)
// 		{
// 			std::cout << it[0] << " ";
// 		}
// 		std::cout << std::endl;
// 		return ;
// 	}
// 	std::stringstream ss0;
// 	std::stringstream ss1;
// 	for (Iterator it = start; it != end; it++)
// 	{
// 		typename Iterator::iterator_type tmp = it.base();
// 		ss0 << " ";
// 		ss1 << "[";
// 		for (size_t k = 0; k < it.size(); k++)
// 		{
// 			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
// 				ss0 << " ";
// 			if (*tmp == *it)
// 				ss0 << "v";
// 			else
// 				ss0 << " ";
// 			ss1 << *tmp;
// 			if (k + 1 < it.size())
// 			{
// 				ss0 << "  ";
// 				ss1 << ", ";	
// 			}
// 			tmp++;
// 		}
// 		ss0 << " ";
// 		ss1 << "]";
// 	}
// 	std::cout << ss0.str() << std::endl;
// 	std::cout << ss1.str() << std::endl;
// 	std::cout << std::endl;
// }

// template<class Iterator>
// void	PmergeMe::printIterator( Iterator start, Iterator end, Iterator last )
// {
// 	if (start.size() == 1)
// 	{
// 		for (Iterator it = start; it != end; it++)
// 		{
// 			std::cout << it[0] << " ";
// 		}
// 		if (*end != *last)
// 			std::cout << "| " << *end;
// 		std::cout << std::endl;
// 		return ;
// 	}
// 	std::stringstream ss0;
// 	std::stringstream ss1;
// 	for (Iterator it = start; it != end; it++)
// 	{
// 		typename Iterator::iterator_type tmp = it.base();
// 		ss0 << " ";
// 		ss1 << "[";
// 		for (size_t k = 0; k < it.size(); k++)
// 		{
// 			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
// 				ss0 << " ";
// 			if (*tmp == *it)
// 				ss0 << "v";
// 			else
// 				ss0 << " ";
// 			ss1 << *tmp;
// 			if (k + 1 < it.size())
// 			{
// 				ss0 << "  ";
// 				ss1 << ", ";	
// 			}
// 			tmp++;
// 		}
// 		ss0 << " ";
// 		ss1 << "]";
// 	}
// 	if (end != last)
// 	{
// 		typename Iterator::iterator_type tmp = end.base();
// 		ss0 << "    ";
// 		ss1 << " | [";
// 		for (size_t k = 0; k < end.size(); k++)
// 		{
// 			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
// 				ss0 << " ";
// 			if (*tmp == *end)
// 				ss0 << "v";
// 			else
// 				ss0 << " ";
// 			ss1 << *tmp;
// 			if (k + 1 < end.size())
// 			{
// 				ss0 << "  ";
// 				ss1 << ", ";
// 			}
// 			tmp++;
// 		}
// 		ss0 << " ";
// 		ss1 << "]";
// 	}
// 	std::cout << ss0.str() << std::endl;
// 	std::cout << ss1.str() << std::endl;
// 	std::cout << std::endl;
// }

// template<class Iterator>
// void	PmergeMe::mergeInsertionSortImpl( Iterator first, Iterator last )
// {
// 	size_t		size = std::distance(first.base(), last.base()) / first.size();
// 	if (size < 2)
// 		return ;
// 	bool		isSizeOdd = size % 2 != 0;
// 	Iterator	end = isSizeOdd ? last - 1 : last;
// 	Iterator&	start = first;
// 	sortAdjacentPairs(start, end);

// 	if (size >= 4)
// 		mergeInsertionSortImpl(Iterator(first, first.size() * 2), Iterator(end, end.size() * 2));
	

// 	std::list<Iterator>									chain;
// 	std::vector<typename std::list<Iterator>::iterator>	chainPos;
// 	initialiseChain(chain, chainPos, start, end, size);

// 	insertElements<Iterator>(chain, chainPos, start + 2, isSizeOdd);

// 	passChainToIterator(chain, start, last);
// }

// template<class Iterator>
// void	PmergeMe::initialiseChain( std::list<Iterator> & chain, std::vector<typename std::list<Iterator>::iterator> & chainPositions, Iterator start, Iterator end, size_t size )
// {
// 	chain.push_back(start); // a1
// 	chain.push_back(start + 1); // b1
// 	chainPositions.reserve((size + 1) / 2 - 1);
// 	for (Iterator it = start + 2; it != end; it += 2)
// 	{
// 		typename std::list<Iterator>::iterator position = chain.insert(chain.end(), it + 1);
// 		chainPositions.push_back(position);
// 	}
// }

// template<class Iterator>
// void	PmergeMe::sortAdjacentPairs( Iterator start, Iterator end )
// {
// 	for (Iterator it = start; it != end; it += 2)
// 	{
// 		if (it[0] > it[1])
// 			swapIterator(it, it + 1);
// 	}
// }

// template<class Iterator>
// void	PmergeMe::swapIterator( Iterator lhs, Iterator rhs )
// {
// 	typename Iterator::iterator_type	lhsEnd = lhs.base();
// 	advance(lhsEnd, lhs.size());
// 	std::swap_ranges(lhs.base(), lhsEnd, rhs.base());
// 	// std::swap_ranges(lhs.base(), this->next(lhs.base(), lhs.size()), rhs.base());
// }

// template<class Iterator>
// void	PmergeMe::insertElements( std::list<Iterator> & chain,
// 								  std::vector<typename std::list<Iterator>::iterator> & chainPositions,
// 								  Iterator current,
// 								  bool isSizeOdd )
// {
// 	// // print chain
// 	// std::cout << "Chain: " << std::endl;
// 	// for (typename std::list<Iterator>::iterator it = chain.begin(); it != chain.end(); it++)
// 	// {
// 	// 	std::cout << **it << " ";
// 	// 	// std::cout << "Chain element: ";
// 	// 	// printIterator(*it, *it + it->size());
// 	// }
// 	// std::cout << std::endl;
// 	// // print chain positions
// 	// std::cout << "Chain positions: ";
// 	// for (typename std::vector<typename std::list<Iterator>::iterator>::iterator it = chainPositions.begin(); it != chainPositions.end(); it++)
// 	// {
// 	// 	std::cout << ***it << " ";
// 	// }
// 	// std::cout << std::endl;

// 	// std::cout << "Inserting elements" << std::endl;
// 	typename std::vector<typename std::list<Iterator>::iterator>::iterator	chainPosNext = chainPositions.begin();
// 	size_t	k = 3;
// 	while (true)
// 	{
// 		long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
// 		if (distToNextChainPos > std::distance(chainPosNext, chainPositions.end()))
// 			break ;
		
// 		Iterator	it = current + distToNextChainPos * 2;
// 		typename std::vector<typename std::list<Iterator>::iterator>::iterator	chainPosIt = chainPosNext + distToNextChainPos;

// 		while (chainPosNext != chainPosIt)
// 		{
// 			--chainPosIt;
// 			it -= 2;
// 			typename std::list<Iterator>::iterator position = binarySearch<Iterator>(chain.begin(), *chainPosIt, *it);
// 			// std::cout << "Inserting element " << *it << " at position " << **position << std::endl;
// 			// if (position == chain.end())
// 			// 	std::cout << " at the end" << std::endl;
// 			// else
// 			// 	std::cout << " at position " << **position << std::endl;
// 			chain.insert(position, it);
// 		}

// 		std::advance(current, distToNextChainPos * 2);
// 		std::advance(chainPosNext, distToNextChainPos);
// 		k++;
// 	}

// 	// std::cout << "Inserting remaining elements" << std::endl;
// 	if (isSizeOdd)
// 		chainPositions.push_back(chain.end());
// 	while (chainPosNext != chainPositions.end())
// 	{
// 		typename std::list<Iterator>::iterator position = binarySearch<Iterator>(chain.begin(), *chainPosNext, *current);
// 		// std::cout << "Inserting element " << *current << std::endl;
// 		// if (position == chain.end())
// 			// std::cout << " at the end" << std::endl;
// 		// else
// 			// std::cout << " at position " << **position << std::endl;
// 		chain.insert(position, current);
// 		current += 2;
// 		chainPosNext++;
// 	}
// }

// template<class Iterator>
// typename std::list<Iterator>::iterator	PmergeMe::binarySearch(typename std::list<Iterator>::iterator left, typename std::list<Iterator>::iterator right, unsigned int val )
// {
// 	// std::cout << "Binary search" << std::endl;
// 	typename std::list<Iterator>::iterator	mid;
// 	typename std::ptrdiff_t			search_range;
// 	typename std::ptrdiff_t			half_range;

// 	search_range = std::distance(left, right);
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

// template<class Iterator>
// void	PmergeMe::passChainToIterator( std::list<Iterator> chain, Iterator start, Iterator last )
// {
// 	typename Iterator::container_type	cache;
// 	last.base(); // To avoid unused variable warning
// 	// cache.reserve(last - start); // What happens if I don't reserve the cache in advance?
// 	// Answer: The program will still work, but it will be slower because the cache will have to be resized multiple times.
// 	for (typename std::list<Iterator>::iterator it = chain.begin(); it != chain.end(); it++)
// 	{
// 		typename Iterator::iterator_type	begin = it->base();
// 		typename Iterator::iterator_type	end = begin;
// 		std::advance(end, it->size());
// 		while (begin != end)
// 		{
// 			cache.push_back(*begin);
// 			begin++;
// 		}
// 	}
// 	std::swap_ranges(cache.begin(), cache.end(), start.base());
// }

// // template<class Iterator>
// // bool	PmergeMe::isSorted( Iterator first, Iterator last )
// // {
// // 	for (Iterator it = first; it != last - 1; it++)
// // 		if (it[0] > it[1])
// // 			return false;
// // 	return true;
// // }