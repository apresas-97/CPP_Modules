#include "PmergeMe.hpp"

void	PmergeMe::mergeInsertionSort( vector & vec )
{
	this->_time_elapsed[VECTOR] = 0.0;
	this->_elements_count[VECTOR] = vec.size();
	if (vec.size() < 2)
		return ;
	this->timeStart(VECTOR);

	pair_vector	vec_pair;
	for (vector::iterator it = vec.begin(); it != vec.end(); ++it)
		vec_pair.push_back(std::make_pair(*it, 0));

	VIteratorP	start(vec_pair.begin());
	VIteratorP	end(vec_pair.end());
	mergeInsertionSort(start, end);

	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] = vec_pair[i].first;

	this->timeEnd(VECTOR);
}

void	PmergeMe::mergeInsertionSort( vector::iterator first, vector::iterator last )
{
	this->_time_elapsed[VECTOR] = 0.0;
	this->_elements_count[VECTOR] = std::distance(first, last);
	if (this->_elements_count[VECTOR] < 2)
		return ;
	this->timeStart(VECTOR);

	pair_vector	vec_pair;
	for (vector::iterator it = first; it != last; ++it)
		vec_pair.push_back(std::make_pair(*it, 0));

	VIteratorP	start(vec_pair.begin());
	VIteratorP	end(vec_pair.end());
	mergeInsertionSort(start, end);

	pair_vector::iterator it_vp = vec_pair.begin();
	for (vector::iterator it = first; it != last; ++it)
		*it = it_vp++->first;

	this->timeEnd(VECTOR);
}

static void	sortAdjacentPairs( VIteratorP start, VIteratorP end )
{
	for (VIteratorP it = start; it != end; it += 2)
	{
		if (it->first > (it + 1)->first)
			VIteratorP::swap(it, it + 1);
	}
}

static void	initialiseChains( VIteratorP start, VIteratorP end, pair_vector & a, pair_vector & b )
{
	VIteratorP::push(a, start, 0);
	VIteratorP::push(a, start + 1, 1);
	unsigned int	index = 2;
	for (VIteratorP it = start + 2; it != end; ++it)
	{
		VIteratorP::push(b, it, index);
		++it;
		VIteratorP::push(a, it, index);
		++index;
	}
}

static void	insertElements( pair_vector & a, pair_vector & b, size_t it_size, VIteratorP * odd_element )
{
	VIteratorP	a_begin = VIteratorP(a.begin(), it_size);
	VIteratorP	a_end = VIteratorP(a.end(), it_size);
	VIteratorP	b_begin = VIteratorP(b.begin(), it_size);
	VIteratorP	b_end = VIteratorP(b.end(), it_size);
	size_t		k = 3;
	size_t		b_from = 0;
	size_t		b_to = 2;
	size_t		b_size = (b.size() / it_size);
	while (true)
	{
		b_from = PmergeMe::jacobsthalNumber(k);
		if (b_from >= b_size + 2)
			break ;

		for (size_t i = b_from + 1; i > b_to; )
		{
			--i;
			a_begin = a.begin();
			a_end = a.end();
			b_begin = b.begin();
			b_end = b.end();
			VIteratorP	aN = VIteratorP::find(a_begin, a_end, i);
			VIteratorP	bN = VIteratorP::find(b_begin, b_end, i);
			VIteratorP	position = VIteratorP::upperBound(a_begin, aN, bN->first);
			VIteratorP::insert(a, position, bN);
		}
		b_to = b_from + 1;
		++k;
	}
	size_t i = b_to;
	while (i < b_size + 2)
	{
		a_begin = a.begin();
		a_end = a.end();
		b_begin = b.begin();
		b_end = b.end();
		VIteratorP	aN = VIteratorP::find(a_begin, a_end, i);
		VIteratorP	bN = VIteratorP::find(b_begin, b_end, i);
		VIteratorP	position = VIteratorP::upperBound(a_begin, aN, bN->first);
		VIteratorP::insert(a, position, bN);
		++i;
	}
	if (odd_element)
	{
		a_begin = a.begin();
		a_end = a.end();
		VIteratorP	position = VIteratorP::upperBound(a_begin, a_end, (*odd_element)->first); 
		VIteratorP::insert(a, position, *odd_element);
	}
}

static void	mergeChain(VIteratorP first, VIteratorP last, pair_vector & a)
{
	std::copy(a.begin(), a.end(), first.base());
	for (VIteratorP it = first; it != last; ++it)
		it->second = 0;
}

void	PmergeMe::mergeInsertionSort( VIteratorP first, VIteratorP last )
{
	size_t			size = std::distance(first, last);
	if (size < 2)
		return ;

	size_t			it_size = first.size();
	bool			is_size_odd = size % 2 != 0;
	VIteratorP		end = is_size_odd ? last - 1 : last;
	VIteratorP *	odd_element = is_size_odd ? &end : NULL;
	VIteratorP &	start = first;

	sortAdjacentPairs(start, end);

	if (size >= 4)
		mergeInsertionSort(VIteratorP(start, it_size * 2), VIteratorP(end, it_size * 2));

	pair_vector	a;
	pair_vector	b;
	a.reserve(size);
	b.reserve(size);
	initialiseChains(start, end, a, b);

	insertElements(a, b, it_size, odd_element);

	mergeChain(start, last, a);
}
