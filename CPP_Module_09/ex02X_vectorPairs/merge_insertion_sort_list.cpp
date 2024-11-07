#include "PmergeMe.hpp"

void	PmergeMe::mergeInsertionSort( list & lst )
{
	this->_time_elapsed[LIST] = 0.0;
	this->_elements_count[LIST] = lst.size();
	if (lst.size() < 2)
		return ;
	this->timeStart(LIST);

	LIterator	start(lst.begin());
	LIterator	end(lst.end());
	mergeInsertionSort(start, end);
	this->timeEnd(LIST);
}

void	PmergeMe::mergeInsertionSort( list::iterator first, list::iterator last )
{
	this->_time_elapsed[LIST] = 0.0;
	this->_elements_count[LIST] = std::distance(first, last);
	if (this->_elements_count[LIST] < 2)
		return ;
	this->timeStart(LIST);

	LIterator	start(first);
	LIterator	end(last);
	mergeInsertionSort(start, end);
	this->timeEnd(LIST);
}

static void	sortAdjacentPairs( LIterator start, LIterator end )
{
	for (LIterator it = start; it != end; it += 2)
	{
		if (it[0] > it[1])
			LIterator::swap(it, it + 1);
	}
}

// Initialised the mainchain and mainchain_positions to their initial values
static void	initialiseChain( LIterator_list & mainchain, LIterator_position_list & mainchain_positions, LIterator start, LIterator end, bool is_size_odd )
{
	// The first two elements will always be the first two elements of the mainchain
	mainchain.push_back(start);
	mainchain.push_back(start + 1);
	for (LIterator it = start + 2; it != end; it += 2)
	{
		// Insert the elements in even positions in the mainchain, and store their positions in mainchain_positions
		LIterator_list::iterator	position = mainchain.insert(mainchain.end(), it + 1);
		mainchain_positions.push_back(position);
	}
	// Add a last position to mainchain_positions if there is an unpaired element left
	if (is_size_odd)
		mainchain_positions.push_back(mainchain.end()); // actually points to LIterator "last", the left out element
}

// Returns the first element in the range [first, last) that is greater than val
static LIterator_list::iterator	customUpperBound( LIterator_list::iterator first, LIterator_list::iterator last, unsigned int val )
{
	LIterator_list::iterator	it;
	LIterator::difference_type	step;
	LIterator::difference_type	count = std::distance(first, last);

	while (count > 0)
	{
		it = first;
		step = count / 2;
		std::advance (it, step);
		if (!(val < *(*it)))
		{
			first = ++it;
			count -= step + 1;
		}
		else
			count = step;
	}
	return first;
}

static void	insertElements(	LIterator_list & mainchain,
							LIterator_position_list & mainchain_positions,
							LIterator b_end )
{
	// Starting point for the mainchain positions
	LIterator_position_list::iterator	a_end_pos = mainchain_positions.begin();
	// To get the kth Jacobsthal number
	size_t								k = 3;
	// Main loop: inserts b elements into the mainchain based on the Jacobsthal sequence
	while (true)
	{
		// Calculate the distance to the next bN and aN elements
		long	distance_to_next = PmergeMe::jacobsthalNumber(k) - PmergeMe::jacobsthalNumber(k - 1);
		// If the distance to the next aN is greater than the remaining insertion points, break
		if (distance_to_next > std::distance(a_end_pos, mainchain_positions.end()))
			break ;

		// b_it points to the next bN element
		LIterator							b_it = b_end;
		std::advance(b_it, distance_to_next * 2);
		// a_it_pos points to the position of the next aN element
		LIterator_position_list::iterator	a_it_pos = a_end_pos;
		std::advance(a_it_pos, distance_to_next);

		// Insert the elements in reverse order from bN to b_end into the mainchain
		while (a_it_pos != a_end_pos)
		{
			--a_it_pos;
			b_it -= 2;
			// Find the insertion position in the mainchain using a binary search
			LIterator_list::iterator	position = customUpperBound(mainchain.begin(), *a_it_pos, *b_it);
			mainchain.insert(position, b_it);
		}

		// Move the b_end and a_end_pos to the next positions at the next bN and aN
		std::advance(b_end, distance_to_next * 2);
		std::advance(a_end_pos, distance_to_next);
		++k;
	}
	// Final loop: inserts the remaining b elements into the mainchain
	while (a_end_pos != mainchain_positions.end())
	{
		// Find the insertion point in the mainchain using a binary search
		LIterator_list::iterator	position = customUpperBound(mainchain.begin(), *a_end_pos, *b_end);
		mainchain.insert(position, b_end);
		b_end += 2;
		++a_end_pos;
	}
}

static void	mergeChain( LIterator_list mainchain, LIterator start )
{
	LIterator::container_type	cache;
	for (LIterator_list::iterator it = mainchain.begin(); it != mainchain.end(); ++it)
	{
		LIterator::iterator_type	it2_end = it->end();
		for (LIterator::iterator_type it2 = it->base(); it2 != it2_end; ++it2)
			cache.push_back(*it2);
	}
	std::swap_ranges(cache.begin(), cache.end(), start.base());
}

void	PmergeMe::mergeInsertionSort( LIterator first, LIterator last )
{
	size_t		size = std::distance(first, last);
	if (size < 2)
		return ;

	size_t		it_size = first.size();
	bool		is_size_odd = size % 2 != 0;
	LIterator	end = is_size_odd ? last - 1 : last;
	LIterator &	start = first;

	sortAdjacentPairs(start, end);

	if (size >= 4)
		mergeInsertionSort(LIterator(start, it_size * 2), LIterator(end, it_size * 2));

	LIterator_list			mainchain;
	LIterator_position_list	mainchain_positions;
	initialiseChain(mainchain, mainchain_positions, start, end, is_size_odd);

	insertElements(mainchain, mainchain_positions, start + 2);

	mergeChain(mainchain, start);
}
