#include "PmergeMe.hpp"

void	PmergeMe::mergeInsertionSort( vector & vec )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = vec.size();
	if (vec.size() < 2)
		return ;
	this->timeStart(VECTOR);

	VIterator	start(vec.begin());
	VIterator	end(vec.end());
	mergeInsertionSort(start, end);
	this->timeEnd(VECTOR);
}

static void	swapVIterator( VIterator lhs, VIterator rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}

static void	sortAdjacentPairs( VIterator start, VIterator end )
{
	for (VIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			swapVIterator(it, it + 1);
	}
}

static void	pushVIterator( std::vector<unsigned int> & v, VIterator iterator )
{
	for (VIterator::iterator_type it = iterator.base(); it != iterator.end(); ++it)
		v.push_back(*it);
}

static void	insertVIterator( std::vector<unsigned int> & v, VIterator position, VIterator val )
{
	VIterator::iterator_type	pos = position.base();
	for (VIterator::iterator_type it = val.base(); it != val.end(); ++it)
		v.insert(pos++, *it);
}

static void	initialiseChains( VIterator start, VIterator end, std::vector<unsigned int> & a, std::vector<unsigned int> & b )
{
	pushVIterator(a, start);
	pushVIterator(a, start + 1);
	for (VIterator it = start + 2; it != end; ++it)
	{
		pushVIterator(b, it);
		++it;
		pushVIterator(a, it);
	}
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

// 2^n - 1
static size_t	twoPowerNMinusOne( size_t n )
{
	return (1 << n) - 1;
}

static VIterator	binarySearch(	VIterator left,
									size_t	search_range,
									unsigned int val )
{
	VIterator	mid = left;
	size_t		half_range;
	while (search_range > 0)
	{
		mid = left;
		half_range = search_range / 2;
		std::advance(mid, half_range);
		if (!(val < *mid))
		{
			++mid;
			left = mid;
			search_range -= half_range + 1;
		}
		else
			search_range = half_range;
	}
	return left;
}

static void	insertElements( std::vector<unsigned int> & a, std::vector<unsigned int> & b, size_t itSize )
{
	VIterator bIt(b.begin(), itSize);
	size_t	k = 3;
	size_t	bStart = 0;
	size_t	bEnd = 0;
	size_t	search_range;
	size_t	bSize = (b.size() / itSize);
	while (true)
	{
		search_range = twoPowerNMinusOne(k - 1);
		bStart = getJacobsthalNumber(k) - 2;
		if (bStart >= bSize)
			break ;
		for (size_t i = bStart + 1; i > bEnd; )
		{
			--i;
			VIterator	position = binarySearch(VIterator(a.begin(), itSize), search_range, bIt[i]);
			insertVIterator(a, position, bIt + i);
		}
		bEnd = bStart + 1;
		++k;
	}
	while (bEnd < bSize)
	{
		search_range = a.size() / itSize;
		VIterator	position = binarySearch(VIterator(a.begin(), itSize), search_range, bIt[bEnd]);
		insertVIterator(a, position, bIt + bEnd);
		++bEnd;
	}
}

void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	size_t	size = std::distance(first, last);
	if (size < 2)
		return ;
	VIterator	end = size % 2 != 0 ? last - 1 : last;
	VIterator &	start = first;
	size_t		itSize = first.size();

	sortAdjacentPairs(start, end);

	if (size >= 4)
		mergeInsertionSort(VIterator(start, itSize * 2), VIterator(end, itSize * 2));

	std::vector<unsigned int>	a;
	std::vector<unsigned int>	b;
	a.reserve(size);
	b.reserve(size / 2);
	initialiseChains(start, end, a, b);
	if (size % 2 != 0)
		pushVIterator(b, end);

	insertElements(a, b, itSize);

	std::swap_ranges(a.begin(), a.end(), start.base());
}