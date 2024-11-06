#include "PmergeMe.hpp"

void	PmergeMe::mergeInsertionSort( vector & vec )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = vec.size();
	if (vec.size() < 2)
		return ;
	this->timeStart(VECTOR);

	std::vector<std::pair<unsigned int, unsigned int> > vecPair;
	for (vector::iterator it = vec.begin(); it != vec.end(); ++it)
		vecPair.push_back(std::make_pair(*it, 0));

	VIteratorP	start(vecPair.begin());
	VIteratorP	end(vecPair.end());
	mergeInsertionSort(start, end);

	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] = vecPair[i].first;

	this->timeEnd(VECTOR);
}

void	PmergeMe::mergeInsertionSort( vector::iterator first, vector::iterator last )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = std::distance(first, last);
	if (this->_elementsCount[VECTOR] < 2)
		return ;
	this->timeStart(VECTOR);

	std::vector<std::pair<unsigned int, unsigned int> > vecPair;
	for (vector::iterator it = first; it != last; ++it)
		vecPair.push_back(std::make_pair(*it, 0));

	VIteratorP	start(vecPair.begin());
	VIteratorP	end(vecPair.end());
	mergeInsertionSort(start, end);

	vector_pair::iterator itP = vecPair.begin();
	for (vector::iterator it = first; it != last; ++it)
		*it = itP++->first;

	this->timeEnd(VECTOR);
}

static void	sortAdjacentPairs( VIteratorP start, VIteratorP end )
{
	for (VIteratorP it = start; it != end; it += 2)
	{
		// std::cout << "Y" << std::endl;
		if (it->first > (it + 1)->first)
			VIteratorP::swap(it, it + 1);
	}
}

static void	initialiseChains( VIteratorP start, VIteratorP end, std::vector<std::pair<unsigned int, unsigned int> > & a, std::vector<std::pair<unsigned int, unsigned int> > & b )
{
	VIteratorP::push(a, start, 0);
	VIteratorP::push(a, start + 1, 1);
	unsigned int index = 2;
	for (VIteratorP it = start + 2; it != end; ++it)
	{
		VIteratorP::push(b, it, index);
		++it;
		VIteratorP::push(a, it, index);
		++index;
	}
}

static void	insertElements( std::vector<std::pair<unsigned int, unsigned int> > & a, std::vector<std::pair<unsigned int, unsigned int> > & b, size_t itSize, VIteratorP * oddElement )
{
	VIteratorP	aBegin = VIteratorP(a.begin(), itSize);
	VIteratorP	aEnd = VIteratorP(a.end(), itSize);
	VIteratorP	bBegin = VIteratorP(b.begin(), itSize);
	VIteratorP	bEnd = VIteratorP(b.end(), itSize);
	size_t		k = 3;
	size_t		bFrom = 0;
	size_t		bTo = 2;
	size_t		bSize = (b.size() / itSize);
	while (true)
	{
		bFrom = jacobsthalNumber(k);
		if (bFrom >= bSize + 2)
			break ;

		for (size_t i = bFrom + 1; i > bTo; )
		{
			--i;
			aBegin = a.begin();
			aEnd = a.end();
			bBegin = b.begin();
			bEnd = b.end();
			VIteratorP	aN = VIteratorP::find(aBegin, aEnd, i);
			VIteratorP	bN = VIteratorP::find(bBegin, bEnd, i);
			VIteratorP	position = VIteratorP::upperBound(aBegin, aN, bN->first);
			VIteratorP::insert(a, position, bN);
		}
		bTo = bFrom + 1;
		++k;
	}
	size_t i = bTo;
	while (i < bSize + 2)
	{
		aBegin = a.begin();
		aEnd = a.end();
		bBegin = b.begin();
		bEnd = b.end();
		VIteratorP	aN = VIteratorP::find(aBegin, aEnd, i);
		VIteratorP	bN = VIteratorP::find(bBegin, bEnd, i);
		VIteratorP	position = VIteratorP::upperBound(aBegin, aN, bN->first);
		VIteratorP::insert(a, position, bN);
		++i;
	}
	if (oddElement)
	{
		aBegin = a.begin();
		aEnd = a.end();
		VIteratorP	position = VIteratorP::upperBound(aBegin, aEnd, (*oddElement)->first); 
		VIteratorP::insert(a, position, *oddElement);
	}
}

static void	mergeChain(VIteratorP first, VIteratorP last, std::vector<std::pair<unsigned int, unsigned int> > & a)
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

	size_t			itSize = first.size();
	bool			isSizeOdd = size % 2 != 0;
	VIteratorP		end = isSizeOdd ? last - 1 : last;
	VIteratorP *	oddElement = isSizeOdd ? &end : NULL;
	VIteratorP &	start = first;

	sortAdjacentPairs(start, end);

	if (size >= 4)
		mergeInsertionSort(VIteratorP(start, itSize * 2), VIteratorP(end, itSize * 2));

	std::vector<std::pair<unsigned int, unsigned int> >	a;
	std::vector<std::pair<unsigned int, unsigned int> >	b;
	a.reserve(size);
	b.reserve(size);
	initialiseChains(start, end, a, b);

	insertElements(a, b, itSize, oddElement);

	mergeChain(start, last, a);
}
