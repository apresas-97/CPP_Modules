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

static void	swapLIterator( LIterator lhs, LIterator rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}

static void	sortAdjacentPairs( LIterator start, LIterator end )
{
	for (LIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapLIterator(it, it + 1);
	}
}

// static void	pushLIterator( std::list<unsigned int> & lst, LIterator iterator )
// {
// 	for (LIterator::iterator_type it = iterator.base(); it != iterator.end(); ++it)
// 		lst.push_back(*it);
// }

// // position should be the .base of the iterator, or the equivalent. Meaning the iterator 0 in a bundle of iterators.
// static std::list<unsigned int>::iterator	insertLIterator( std::list<unsigned int> & lst, std::list<unsigned int>::iterator position, LIterator val )
// {
// 	// LIterator::iterator_type	pos = position.base();
// 	std::list<unsigned int>::iterator	insertedPosition;
// 	// bool first = true;
// 	for (LIterator::iterator_type it = val.base(); it != val.end(); ++it)
// 	{
// 		// if (first)
// 		// {
// 			insertedPosition = lst.insert(position, *it);
// 			// first = false;
// 		// }
// 		// else
// 		// {
// 		// 	lst.insert(position, *it);
// 		// }
// 	}
// 	std::advance(insertedPosition, -val.size()); // ? hopefully this works as I think it does
// 	// Since the latest value of insertedPosition will be the last element of the inserted range,
// 	// We step back by the size of val, to get the first element of the inserted range, which is the one we want to return.
// 	return insertedPosition;
// }

// static LIterator	insertLIterator( std::list<unsigned int> & lst, std::list<unsigned int>::iterator position, LIterator val )
// {
// 	// LIterator::iterator_type	pos = position.base();
// 	std::list<unsigned int>::iterator	insertedPosition;
// 	for (LIterator::iterator_type it = val.base(); it != val.end(); ++it)
// 		insertedPosition = lst.insert(position, *it);
// 	std::advance(insertedPosition, -val.size()); // ? hopefully this works as I think it does
// 	// Since the latest value of insertedPosition will be the last element of the inserted range,
// 	// We step back by the size of val, to get the first element of the inserted range, which is the one we want to return.
// 	return LIterator(insertedPosition, val.size());
// }

// static LIterator	insertLIterator( std::list<unsigned int> & lst, LIterator position, LIterator val )
// {
// 	LIterator::iterator_type	pos = position.base();
// 	for (LIterator::iterator_type it = val.base(); it != val.end(); ++it)
// 		lst.insert(pos, *it);
// }

////////////
// static void	initialiseChain( std::list<unsigned int> & mainchain, std::list<std::list<unsigned int>::iterator> & mainchainPositions, std::list<unsigned int> & pend, LIterator start, LIterator end, bool isSizeOdd )
// {
// 	pushLIterator(mainchain, start);
// 	pushLIterator(mainchain, start + 1);
// 	for (LIterator it = start + 2; it != end; it += 2)
// 	{
// 		pushLIterator(pend, it);
// 		// pend.push_back(it);
// 		// std::list<unsigned int>::iterator	position = mainchain.insert(mainchain.end(), it + 1);
// 		std::list<unsigned int>::iterator	position = insertLIterator(mainchain, mainchain.end(), it + 1);
// 		mainchainPositions.push_back(position);
// 	}
// 	(void)isSizeOdd; // for now
// 	// if (isSizeOdd)
// 	// {
// 	// 	// pend.push_back(*end);
// 	// 	pushLIterator(pend, end);
// 	// 	mainchainPositions.push_back(mainchain.end()); // actually points to LIterator "last", the left out element
// 	// 	// mainchainPositions.push_back(end); // actually points to LIterator "last", the left out element
// 	// }
// }

// static void	initialiseChain( std::list<unsigned int> & mainchain, std::list<LIterator> & mainchainPositions, std::list<unsigned int> & pend, LIterator start, LIterator end, bool isSizeOdd )
// {
// 	pushLIterator(mainchain, start);
// 	pushLIterator(mainchain, start + 1);
// 	for (LIterator it = start + 2; it != end; it += 2)
// 	{
// 		pushLIterator(pend, it);
// 		// pend.push_back(it);
// 		// std::list<unsigned int>::iterator	position = mainchain.insert(mainchain.end(), it + 1);
// 		LIterator	position = insertLIterator(mainchain, mainchain.end(), it + 1);
// 		mainchainPositions.push_back(position);
// 	}
// 	if (isSizeOdd)
// 	{
// 		// pend.push_back(end);
// 		pushLIterator(pend, end);
// 		// mainchainPositions.push_back(mainchain.end()); // actually points to LIterator "last", the left out element
// 		mainchainPositions.push_back(end); // actually points to LIterator "last", the left out element
// 	}
// }

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

static long	getJacobsthalNumber( unsigned int k )
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;

	long	a = 0;
	long	b = 1;
	long	c;
	for (unsigned int i = 2; i <= k; ++i)
	{
		c = b + 2 * a;
		a = b;
		b = c;
	}
	return b;
}

// // 2^n - 1
// static size_t	twoPowerNMinusOne( size_t n )
// {
// 	return (1 << n) - 1;
// }

// static LIterator	binarySearch(	LIterator left,
// 									size_t	search_range,
// 									unsigned int val )
// {
// 	LIterator	mid = left;
// 	size_t		half_range;
// 	while (search_range > 0)
// 	{
// 		mid = left;
// 		half_range = search_range / 2;
// 		std::advance(mid, half_range);
// 		if (!(val < *mid))
// 		{
// 			++mid;
// 			left = mid;
// 			search_range -= half_range + 1;
// 		}
// 		else
// 			search_range = half_range;
// 	}
// 	return left;
// }

/////////////////////////////
// static LIterator	binarySearch( LIterator left, LIterator right, LIterator val )
// {
// 	std::cout << "=====================Binary search" << std::endl;

// 	std::cout << "left = " << *left << std::endl;
// 	std::cout << "right = " << *right << std::endl;
// 	std::cout << "Left.size = " << left.size() << std::endl;
// 	std::cout << "list of values:" << std::endl;
// 	for (LIterator it = left; it != right; ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;

// 	// std::list<LIterator>::iterator	mid;
// 	// std::ptrdiff_t			search_range;
// 	// std::ptrdiff_t			half_range;
// 	LIterator	mid = left;
// 	size_t		searchRange = std::distance(left, right) / val.size();
// 	size_t		halfRange;
// 	std::cout << "Search range = " << searchRange << std::endl;
// 	while (searchRange > 0)
// 	{
// 		std::cout << "binarySearch loop" << std::endl;
// 		// std::cout << "Search range = " << searchRange << std::endl;
// 		halfRange = searchRange / 2;
// 		mid = left + halfRange;
// 		// std::advance (mid, halfRange);
// 		// std::cout << "Comparing " << val << " with " << *(*mid) << std::endl;
// 		if (!(*val < *mid))
// 		{
// 			++mid;
// 			left = mid;
// 			searchRange -= halfRange + 1;
// 		}
// 		else
// 			searchRange = halfRange;
// 	}
// 	if (left == right)
// 		std::cout << "Returning end" << std::endl;
// 	else
// 		std::cout << "Returning position " << *left.base() << std::endl;
// 	return left;
// }

static std::list<LIterator>::iterator	binarySearch( std::list<LIterator>::iterator left, std::list<LIterator>::iterator right, unsigned int val )
{
	// std::cout << "Binary search" << std::endl;
	std::list<LIterator>::iterator	mid;
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

// static void	insertElements( std::list<unsigned int> & a, std::list<unsigned int> & b, size_t itSize, bool isSizeOdd )
// {
// 	(void)isSizeOdd; // for now
// 	LIterator bIt(b.begin(), itSize);
// 	size_t	k = 3;
// 	size_t	bStart = 0;
// 	size_t	bEnd = 0;
// 	size_t	search_range;
// 	size_t	bSize = (b.size() / itSize);
// 	while (true)
// 	{
// 		search_range = twoPowerNMinusOne(k - 1);
// 		bStart = getJacobsthalNumber(k) - 2;
// 		if (bStart >= bSize)
// 			break ;
// 		for (size_t i = bStart + 1; i > bEnd; )
// 		{
// 			--i;
// 			LIterator	position = binarySearch(LIterator(a.begin(), itSize), search_range, bIt[i]);
// 			insertLIterator(a, position, bIt + i);
// 		}
// 		bEnd = bStart + 1;
// 		++k;
// 	}
// 	while (bEnd < bSize)
// 	{
// 		search_range = a.size() / itSize;
// 		LIterator	position = binarySearch(LIterator(a.begin(), itSize), search_range, bIt[bEnd]);
// 		insertLIterator(a, position, bIt + bEnd);
// 		++bEnd;
// 	}
// }

static void	insertElements(	std::list<LIterator> & chain,
							std::list<std::list<LIterator>::iterator> & chainPositions,
							LIterator current )
{
	std::list<std::list<LIterator>::iterator>::iterator chainPosNext = chainPositions.begin();
	size_t	k = 3;
	while (true)
	{
		long	distToNextChainPos = getJacobsthalNumber(k) - getJacobsthalNumber(k - 1);
		if (distToNextChainPos > std::distance(chainPosNext, chainPositions.end()))
			break ;
		
		LIterator	it = current + distToNextChainPos * 2;
		std::list<std::list<LIterator>::iterator>::iterator	chainPosIt = chainPosNext;
		std::advance(chainPosIt, distToNextChainPos);

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
	while (chainPosNext != chainPositions.end())
	{
		std::list<LIterator>::iterator position = binarySearch(chain.begin(), *chainPosNext, *current);
		chain.insert(position, current);
		current += 2;
		chainPosNext++;
	}
}

/////////////////////////////
// static void	insertElements( std::list<unsigned int> & mainchain,
// 							std::list<std::list<unsigned int>::iterator> & mainchainPositions,
// 							std::list<unsigned int> & pend,
// 							size_t itSize )
// {

// 	std::cout << "Inserting elements" << std::endl;
// 	std::list<std::list<unsigned int>::iterator>::iterator	mainchainPositionsBegin = mainchainPositions.begin();
// 	// LIterator<std::list<LIterator>::iterator> mainchainPositionsBegin(mainchainPositions.begin());
// 	size_t		k = 3;
// 	size_t		pendEndIndex = 0;
// 	// LIterator	pendIt(pend.begin(), (mainchain.begin())->size()); // for now
// 	LIterator	pendBegin(pend.begin(), itSize);
// 	// LIterator	mainchainBegin(mainchain.begin(), itSize);
// 	// LIterator	pendIt(pend.begin(), itSize);
// 	size_t		pendSize = pend.size() / itSize;
// 	while (true)
// 	{
// 		std::cout << "Main Insert Loop" << std::endl;
// 		size_t	pendStartIndex = getJacobsthalNumber(k) - 2;

// 		std::cout << "pendStartIndex = " << pendStartIndex << std::endl;
// 		std::cout << "pend.size() = " << pendSize << std::endl;
// 		if (pendStartIndex >= pendSize)
// 			break ;

// 		LIterator pendIt = pendBegin + pendStartIndex;
// 		// LIterator	pendIt = current + distToNextChainPos * 2;

// 		// LIterator<std::list<LIterator>::iterator>	chainPosIt = mainchainPositionsBegin + distToNextChainPos;
// 		std::list<std::list<unsigned int>::iterator>::iterator	mainchainPositionIt = mainchainPositionsBegin;
// 		std::advance(mainchainPositionIt, pendStartIndex);

// 		for (size_t i = pendStartIndex + 1; i > pendEndIndex; )
// 		{
// 			std::cout << "bX Insert Loop" << std::endl;
// 			--i;
// 			LIterator position = binarySearch(LIterator(mainchain.begin(), itSize), *mainchainPositionIt, pendIt);
// 			// std::list<std::list<unsigned int>::iterator>::iterator position = binarySearch(mainchain.begin(), *mainchainPositionIt, *pendIt);
// 			std::cout << "Inserting element " << *pendIt << std::endl;
// 			if (position == mainchain.end())
// 				std::cout << " at the end" << std::endl;
// 			else
// 				std::cout << " at position " << *position << std::endl;
// 			// mainchain.insert(position, pendIt);
// 			insertLIterator(mainchain, position.base(), pendIt);
// 			--mainchainPositionIt;
// 			--pendIt;
// 		}
// 		pendEndIndex = pendStartIndex + 1;
// 		++k;
// 	}
// 	std::cout << "Main insert loop OUT" << std::endl;
// 	std::cout << "pendEndIndex = " << pendEndIndex << std::endl;
// 	std::cout << "pendSize = " << pendSize << std::endl;
// 	while (pendEndIndex < pendSize)
// 	{
// 		std::cout << "Secondary Insert Loop" << std::endl;
// 		LIterator	mainchainBegin(mainchain.begin(), itSize);
// 		LIterator	position = binarySearch(mainchainBegin, mainchainBegin + mainchain.size(), pendBegin + pendEndIndex);
// 		std::cout << "Inserting element " << *(pendBegin + pendEndIndex) << std::endl;
// 		if (position == mainchain.end())
// 			std::cout << " at the end" << std::endl;
// 		else
// 			std::cout << " at position " << *position << std::endl;
// 		// mainchain.insert(position, pendBegin + pendEndIndex);
// 		insertLIterator(mainchain, position.base(), pendBegin + pendEndIndex);
// 		++pendEndIndex;
// 	}
// }

// static void	insertElements( std::list<unsigned int> & mainchain,
// 							std::list<LIterator> & mainchainPositions,
// 							std::list<unsigned int> & pend,
// 							size_t itSize )
// {

// 	std::cout << "Inserting elements" << std::endl;
// 	std::list<LIterator>::iterator	mainchainPositionsBegin = mainchainPositions.begin();
// 	// LIterator<std::list<LIterator>::iterator> mainchainPositionsBegin(mainchainPositions.begin());
// 	size_t		k = 3;
// 	size_t		pendEndIndex = 0;
// 	// LIterator	pendIt(pend.begin(), (mainchain.begin())->size()); // for now
// 	LIterator	pendBegin(pend.begin(), itSize);
// 	LIterator	mainchainBegin(mainchain.begin(), itSize);
// 	// LIterator	pendIt(pend.begin(), itSize);
// 	while (true)
// 	{
// 		std::cout << "Main Insert Loop" << std::endl;
// 		size_t	pendStartIndex = getJacobsthalNumber(k) - 2;

// 		if (pendStartIndex >= pend.size())
// 			break ;

// 		LIterator pendIt = pendBegin + pendStartIndex;
// 		// LIterator	pendIt = current + distToNextChainPos * 2;

// 		// LIterator<std::list<LIterator>::iterator>	chainPosIt = mainchainPositionsBegin + distToNextChainPos;
// 		std::list<LIterator>::iterator	mainchainPositionIt = mainchainPositionsBegin;
// 		std::advance(mainchainPositionIt, pendStartIndex);

// 		for (size_t i = pendStartIndex + 1; i > pendEndIndex; )
// 		{
// 			std::cout << "bX Insert Loop" << std::endl;
// 			--i;
// 			LIterator position = binarySearch(mainchainBegin, *mainchainPositionIt, pendIt);
// 			// std::list<std::list<unsigned int>::iterator>::iterator position = binarySearch(mainchain.begin(), *mainchainPositionIt, *pendIt);
// 			std::cout << "Inserting element " << *pendIt << std::endl;
// 			if (position == mainchain.end())
// 				std::cout << " at the end" << std::endl;
// 			else
// 				std::cout << " at position " << *position << std::endl;
// 			// mainchain.insertstatic void	insertElements( std::list<unsigned int> & mainchain,
// 							std::list<LIterator> & mainchainPositions,
// 							std::list<unsigned int> & pend,
// 							size_t itSize )
// {

// 	std::cout << "Inserting elements" << std::endl;
// 	std::list<LIterator>::iterator	mainchainPositionsBegin = mainchainPositions.begin();
// 	// LIterator<std::list<LIterator>::iterator> mainchainPositionsBegin(mainchainPositions.begin());
// 	size_t		k = 3;
// 	size_t		pendEndIndex = 0;
// 	// LIterator	pendIt(pend.begin(), (mainchain.begin())->size()); // for now
// 	LIterator	pendBegin(pend.begin(), itSize);
// 	LIterator	mainchainBegin(mainchain.begin(), itSize);
// 	// LIterator	pendIt(pend.begin(), itSize);
// 	while (true)
// 	{
// 		std::cout << "Main Insert Loop" << std::endl;
// 		size_t	pendStartIndex = getJacobsthalNumber(k) - 2;

// 		if (pendStartIndex >= pend.size())
// 			break ;

// 		LIterator pendIt = pendBegin + pendStartIndex;
// 		// LIterator	pendIt = current + distToNextChainPos * 2;

// 		// LIterator<std::list<LIterator>::iterator>	chainPosIt = mainchainPositionsBegin + distToNextChainPos;
// 		std::list<LIterator>::iterator	mainchainPositionIt = mainchainPositionsBegin;
// 		std::advance(mainchainPositionIt, pendStartIndex);

// 		for (size_t i = pendStartIndex + 1; i > pendEndIndex; )
// 		{
// 			std::cout << "bX Insert Loop" << std::endl;
// 			--i;
// 			LIterator position = binarySearch(mainchainBegin, *mainchainPositionIt, pendIt);
// 			// std::list<std::list<unsigned int>::iterator>::iterator position = binarySearch(mainchain.begin(), *mainchainPositionIt, *pendIt);
// 			std::cout << "Inserting element " << *pendIt << std::endl;
// 			if (position == mainchain.end())
// 				std::cout << " at the end" << std::endl;
// 			else
// 				std::cout << " at position " << *position << std::endl;
// 			// mainchain.insert(position, pendIt);
// 			insertLIterator(mainchain, position.base(), pendIt);
// 			--mainchainPositionIt;
// 			--pendIt;
// 		}
// 		pendEndIndex = pendStartIndex + 1;
// 		++k;
// 	}
// 	while (pendEndIndex < pend.size())
// 	{
// 		std::cout << "Secondary Insert Loop" << std::endl;
// 		LIterator	position = binarySearch(mainchainBegin, mainchainBegin + mainchain.size(), pendBegin + pendEndIndex);
// 		std::cout << "Inserting element " << *(pendBegin + pendEndIndex) << std::endl;
// 		if (position == mainchain.end())
// 			std::cout << " at the end" << std::endl;
// 		else
// 			std::cout << " at position " << *position << std::endl;
// 		// mainchain.insert(position, pendBegin + pendEndIndex);
// 		insertLIterator(mainchain, position.base(), pendBegin + pendEndIndex);
// 		++pendEndIndex;
// 	}
// }(position, pendIt);
// 			insertLIterator(mainchain, position.base(), pendIt);
// 			--mainchainPositionIt;
// 			--pendIt;
// 		}
// 		pendEndIndex = pendStartIndex + 1;
// 		++k;
// 	}
// 	while (pendEndIndex < pend.size())
// 	{
// 		std::cout << "Secondary Insert Loop" << std::endl;
// 		LIterator	position = binarySearch(mainchainBegin, mainchainBegin + mainchain.size(), pendBegin + pendEndIndex);
// 		std::cout << "Inserting element " << *(pendBegin + pendEndIndex) << std::endl;
// 		if (position == mainchain.end())
// 			std::cout << " at the end" << std::endl;
// 		else
// 			std::cout << " at position " << *position << std::endl;
// 		// mainchain.insert(position, pendBegin + pendEndIndex);
// 		insertLIterator(mainchain, position.base(), pendBegin + pendEndIndex);
// 		++pendEndIndex;
// 	}
// }

// static void	insertElements( std::list<LIterator> & mainchain,
// 							std::list<std::list<LIterator>::iterator> & mainchainPositions,
// 							std::list<LIterator> & pend )
// {
// 	// // print mainchain
// 	// std::cout << "Chain: " << std::endl;
// 	// for (std::list<LIterator>::iterator it = mainchain.begin(); it != mainchain.end(); it++)
// 	// {
// 	// 	std::cout << **it << " ";
// 	// 	// std::cout << "Chain element: ";
// 	// 	// printLIterator(*it, *it + it->size());
// 	// }
// 	// std::cout << std::endl;
// 	// // print mainchain positions
// 	// std::cout << "Chain positions: ";
// 	// for (std::list<std::list<LIterator>::iterator>::iterator it = mainchainPositions.begin(); it != mainchainPositions.end(); it++)
// 	// {
// 	// 	std::cout << ***it << " ";
// 	// }
// 	// std::cout << std::endl;

// 	// std::cout << "Inserting elements" << std::endl;
// 	std::list<std::list<LIterator>::iterator>::iterator	chainPosNext = mainchainPositions.begin();
// 	// LIterator<std::list<LIterator>::iterator> chainPosNext(mainchainPositions.begin());
// 	size_t		k = 3;
// 	size_t		pendEndIndex = 0;
// 	// LIterator	pendIt(pend.begin(), (mainchain.begin())->size()); // for now
// 	LIterator	pendIt = *pend.begin();
// 	// LIterator	pendIt(pend.begin(), itSize);
// 	while (true)
// 	{
// 		size_t	pendStartIndex = getJacobsthalNumber(k) - 2;
// 		// long	distToNextChainPos = this->_jacobsthalNumbers[k] - this->_jacobsthalNumbers[k - 1];
// 		// if (distToNextChainPos > std::distance(chainPosNext.base(), mainchainPositions.end()))
// 			// break ;

// 		if (pendStartIndex >= pend.size())
// 			break ;

// 		LIterator it = pendIt + pendStartIndex;
// 		// LIterator	it = current + distToNextChainPos * 2;

// 		// LIterator<std::list<LIterator>::iterator>	chainPosIt = chainPosNext + distToNextChainPos;
// 		std::list<std::list<LIterator>::iterator>::iterator	mainchainPosIt = chainPosNext;
// 		std::advance(mainchainPosIt, pendStartIndex);

// 		for (size_t i = pendStartIndex + 1; i > pendEndIndex; )
// 		{
// 			--i;
// 			std::list<LIterator>::iterator position = binarySearch(mainchain.begin(), *mainchainPosIt, *it);
// 			std::cout << "Inserting element " << *it << std::endl;
// 			if (position == mainchain.end())
// 				std::cout << " at the end" << std::endl;
// 			else
// 				std::cout << " at position " << **position << std::endl;
// 			mainchain.insert(position, it);
// 			--mainchainPosIt;
// 			--it;
// 		}
// 		pendEndIndex = pendStartIndex + 1;
// 		++k;

// 		// while (chainPosNext != chainPosIt)
// 		// {
// 		// 	--chainPosIt;
// 		// 	it -= 2;
// 		// 	std::list<LIterator>::iterator position = binarySearch(mainchain.begin(), *chainPosIt, *it);
// 		// 	std::cout << "Inserting element " << *it << " at position " << **position << std::endl;
// 		// 	if (position == mainchain.end())
// 		// 		std::cout << " at the end" << std::endl;
// 		// 	else
// 		// 		std::cout << " at position " << **position << std::endl;
// 		// 	mainchain.insert(position, it);
// 		// }

// 		// std::advance(current, distToNextChainPos * 2);
// 		// std::advance(chainPosNext, distToNextChainPos);
// 		// k++;
// 	}
// 	while (pendEndIndex < pend.size())
// 	{
// 		std::list<LIterator>::iterator	position = binarySearch(mainchain.begin(), mainchain.end(), pendIt[pendEndIndex]);
// 		std::cout << "Inserting element " << *(pendIt + pendEndIndex) << std::endl;
// 		if (position == mainchain.end())
// 			std::cout << " at the end" << std::endl;
// 		else
// 			std::cout << " at position " << **position << std::endl;
// 		mainchain.insert(position, pendIt + pendEndIndex);
// 		++pendEndIndex;
// 	}
// 	// while (chainPosNext != mainchainPositions.end())
// 	// {
// 	// 	std::list<LIterator>::iterator position = binarySearch(mainchain.begin(), *chainPosNext, *current);
// 	// 	std::cout << "Inserting element " << *current << std::endl;
// 	// 	if (position == mainchain.end())
// 	// 		std::cout << " at the end" << std::endl;
// 	// 	else
// 	// 		std::cout << " at position " << **position << std::endl;
// 	// 	mainchain.insert(position, current);
// 	// 	current += 2;
// 	// 	chainPosNext++;
// 	// }
// }

static void	passChainToIterator( std::list<LIterator> chain, LIterator start, LIterator last )
{
	LIterator::container_type	cache;
	last.base(); // To avoid unused variable warning
	for (std::list<LIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		LIterator::iterator_type	begin = it->base();
		LIterator::iterator_type	end = begin;
		std::advance(end, it->size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

// static void	verifyChains( std::list<unsigned int> & mainchain, std::list<std::list<unsigned int>::iterator> & mainchainPos )
// {
// 	std::cout << "Verifying chains" << std::endl;
// 	size_t	limit = 20;
// 	size_t	i = 0;
// 	for (std::list<std::list<unsigned int>::iterator>::iterator it = mainchainPos.begin(); it != mainchainPos.end(); it++)
// 	{
// 		bool found = false;
// 		for (std::list<unsigned int>::iterator it2 = mainchain.begin(); it2 != mainchain.end(); it2++)
// 		{
// 			if (*it2 == **it)
// 			{
// 				found = true;
// 				std::cout << "Element " << i << " found in mainchain" << std::endl;
// 				break ;
// 			}
// 		}
// 		if (found == false)
// 			std::cout << "Element " << i << " not found in mainchain" << std::endl;
// 		--limit;
// 		if (limit == 0)
// 			break ;
// 		++i;
// 	}
// }

void	PmergeMe::mergeInsertionSort( LIterator first, LIterator last )
{
	// std::cout << "IN -----------------------------------------" << std::endl;
	size_t	size = std::distance(first, last);
	if (size < 2)
	{
		// std::cout << "OUT -----------------------------------------" << std::endl;
		return ;
	}
	size_t		itSize = first.size();
	bool		isSizeOdd = size % 2 != 0;
	LIterator	end = isSizeOdd ? last - 1 : last;
	LIterator &	start = first;

	// std::cout << "Before sort pairs" << std::endl;
	// printLIterator(first, last);

	sortAdjacentPairs(start, end);

	// std::cout << "After sort pairs" << std::endl;
	// printLIterator(start, end);

	if (size >= 4)
		mergeInsertionSort(LIterator(start, itSize * 2), LIterator(end, itSize * 2));
	if (size == 2)
	{
		// std::cout << "OUT -----------------------------------------" << std::endl;
		return ;
	}

	std::list<LIterator>						mainchain;
	std::list<std::list<LIterator>::iterator>	mainchainPositions;
	// std::list<LIterator>						pend;
	// initialiseChain(mainchain, mainchainPositions, pend, start, end, isSizeOdd);
		// std::list<unsigned int>							mainchain;
		// std::list<std::list<unsigned int>::iterator>	mainchainPositions;
	// std::list<LIterator>	mainchainPositions;
		// std::list<unsigned int>							pend;
	// initialiseChain(mainchain, mainchainPositions, pend, start, end, isSizeOdd);
	initialiseChain(mainchain, mainchainPositions, start, end, isSizeOdd);

	////////

	// verifyChains(mainchain, mainchainPositions);

	// std::cout << "Printing mainchain's values" << std::endl;
	// size_t i = 1;
	// if (itSize > 1)
	// 	std::cout << "[";
	// for (std::list<unsigned int>::iterator it = mainchain.begin(); it != mainchain.end(); it++)
	// {
	// 	std::cout << *it;
	// 	if (itSize > 1 && i % itSize == 0)
	// 		std::cout << "] [";
	// 	else
	// 		std::cout << " ";
	// 	i++;
	// }
	// std::cout << std::endl;
	// // std::cout << "Printing mainchain's addresses" << std::endl;
	// // for (std::list<unsigned int>::iterator it = mainchain.begin(); it != mainchain.end(); it++)
	// // {
	// // 	std::cout << &(*it) << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Printing mainchainPositions' values" << std::endl;
	// for (std::list<std::list<unsigned int>::iterator>::iterator it = mainchainPositions.begin(); it != mainchainPositions.end(); it++)
	// {
	// 	std::cout << **it << " ";
	// }
	// std::cout << std::endl;
	// // std::cout << "Printing mainchainPositions' addresses" << std::endl;
	// // for (std::list<LIterator>::iterator it = mainchainPositions.begin(); it != mainchainPositions.end(); it++)
	// // {
	// // 	std::cout << &(*it) << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Printing pend's values" << std::endl;
	// for (std::list<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	/////////

	// std::cout << "Before insert Elements" << std::endl;
	// printLIterator(start, end);

	insertElements(mainchain, mainchainPositions, start + 2);
	// insertElements(mainchain, mainchainPositions, pend, start);
	// insertElements(mainchain, mainchainPositions, pend, itSize);
	// insert odd element
	// if (isSizeOdd)
	// {
	// 	std::cout << "Inserting left over element" << std::endl;
	// 	LIterator	position = binarySearch(LIterator(mainchain.begin(), itSize), LIterator(mainchain.end(), itSize), end);
	// 	insertLIterator(mainchain, position.base(), end);
	// }

	passChainToIterator(mainchain, start, last);
	// std::swap_ranges(mainchain.begin(), mainchain.end(), start.base());
	// std::cout << "After insert Elements" << std::endl;
	// printLIterator(start, last);
	// std::cout << "OUT -----------------------------------------" << std::endl;
}