#include "PmergeMe.hpp"

////////////////////////////
static void	printChain( std::vector<std::pair<unsigned int, unsigned int> > & chain, std::string prefix )
{
	std::ostringstream oss0;
	std::ostringstream oss1;
	oss0 << prefix << ": ";
	oss1 << "i: ";
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = chain.begin(); it != chain.end(); it++)
	{
		oss0 << BOLD << it->first << RESET " ";
		oss1 << DIM << it->second << RESET " ";
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
}

static void	printVIteratorP( VIteratorP p )
{
	// std::cout << "VIteratorP: < " << p->first << " , " << p->second << " >" << std::endl;
	// std::cout << BOLD << p->first << std::endl << DIM << p->second << RESET << std::endl;
	std::cout << p->first << std::endl << p->second  << std::endl;
}

static void	printVIteratorP( std::ostringstream & oss0, std::ostringstream & oss1, VIteratorP p )
{
	// oss0 << BOLD << p->first << RESET " ";
	// oss1 << DIM << p->second << RESET " ";
	oss0 << p->first << " ";
	oss1 << p->second << " ";
}

static void	printChain( VIteratorP start, VIteratorP end, std::string prefix )
{
	std::ostringstream oss0;
	std::ostringstream oss1;
	oss0 << prefix << ": ";
	oss1 << "i: ";
	for (VIteratorP it = start; it != end; it++)
	{
		printVIteratorP(oss0, oss1, it);
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
}

static void	printInsertion( std::vector<std::pair<unsigned int, unsigned int> > & v, VIteratorP position, VIteratorP element )
{
	std::cout << "Inserting: " BOLD << element->first << RESET " at position:" << std::endl;
	if (position == v.end())
	{
		std::cout << ITALIC "\tEND" RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << BOLD "\t" << position->first << RESET << std::endl;
		std::cout << DIM "\t" << position->second << RESET << std::endl;
	}
}

/////////////////////////////////////////////////////////////

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

static void	swapVIteratorP( VIteratorP lhs, VIteratorP rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}

static void	sortAdjacentPairs( VIteratorP start, VIteratorP end )
{
	for (VIteratorP it = start; it != end; it += 2)
	{
		// std::cout << "Y" << std::endl;
		// std::cout << it[0].first << " < " << it[1].first << std::endl;
		if (it[0].first > it[1].first)
			swapVIteratorP(it, it + 1);
	}
}

// push a VIteratorP iterator into a vector and assign the index to the last element of the VIteratorP in the resulting vector
static void	pushVIteratorP( std::vector<std::pair<unsigned int, unsigned int> > & v, VIteratorP iterator, unsigned int index )
{
	VIteratorP::iterator_type it = iterator.base();
	while (it != iterator.end() - 1)
		v.push_back(*it++);
	v.push_back(std::make_pair(it->first, index));
}

static void	insertVIteratorP( std::vector<std::pair<unsigned int, unsigned int> > & v, VIteratorP position, VIteratorP val )
{
	VIteratorP::iterator_type	pos = position.base();
	VIteratorP::iterator_type	it = val.base();
	while (it != val.end() - 1)
		v.insert(pos++, *it++);
	v.insert(pos, std::make_pair(it->first, 0)); // set the index to 0 so it doesn't get confused with the values alredy in the vector
}

static void	initialiseChains( VIteratorP start, VIteratorP end, std::vector<std::pair<unsigned int, unsigned int> > & a, std::vector<std::pair<unsigned int, unsigned int> > & b )
{
	pushVIteratorP(a, start, 0);
	pushVIteratorP(a, start + 1, 1);
	unsigned int index = 2;
	for (VIteratorP it = start + 2; it != end; ++it)
	{
		pushVIteratorP(b, it, index);
		++it;
		pushVIteratorP(a, it, index);
		++index;
	}
}

static VIteratorP	binarySearchIndex( VIteratorP first, VIteratorP last, unsigned int val )
{
	// std::cout << "=== BINARY SEARCH ===" << std::endl;
	// std::cout << "Seeking value: " << val << " in chain:" << std::endl;
	// printChain(first, last, "V");
	VIteratorP	it = first;
	size_t		step;
	size_t		count = std::distance(first, last);
	// std::cout << "Range: " << count << std::endl;

	while (count > 0)
	{
		it = first;
		step = count / 2;
		std::advance(it, step);

		// std::cout << "Y" << std::endl;
		// std::cout << it->first << " < " << val << std::endl;
		// if (it->first < val)
		if (!(val < it->first))
		{
			first = ++it;	
			count -= step + 1;
		}
		else
			count = step;
	}
	// std::cout << "Found:" << std::endl;
	// if (it == last)
		// std::cout << "\tLAST" << std::endl;
	// else
		// std::cout << "\t" << first->first <<  std::endl;
	// std::cout <<  "=== BINARY SEARCH DONE ==="  << std::endl;
	return first;
}

// Try it with lower_bound maybe
static bool	compareCustom( std::vector<std::pair<unsigned int, unsigned int> >::iterator lhs, std::vector<std::pair<unsigned int, unsigned int> >::iterator rhs )
{
	return (lhs->first < rhs->first);
}

static VIteratorP	findXN( VIteratorP begin, VIteratorP end, unsigned int index )
{
	// std::cout << BOLD "== findXN ==" RESET << std::endl;
	// std::cout << "Seeking index: " << index << " in chain:" << std::endl;
	// printChain(begin, end, "V");
	for (VIteratorP it = begin; it != end; ++it)
	{
		if (it->second == index)
		{
			// std::cout << BOLD "== findXN DONE ==" RESET << std::endl;
			return it;
		}
	}
	// If not found:
	// std::cout << BOLD RED "Index not found" RESET << std::endl;
	throw std::exception(); // for now
	// return end;
}

static void	insertElements( std::vector<std::pair<unsigned int, unsigned int> > & a, std::vector<std::pair<unsigned int, unsigned int> > & b, size_t itSize, VIteratorP * oddElement )
{
	// std::cout << BOLD "======== INSERT ELEMENTS ========" RESET << std::endl;
	VIteratorP	aBegin = VIteratorP(a.begin(), itSize);
	VIteratorP	aEnd = VIteratorP(a.end(), itSize);
	VIteratorP	bBegin = VIteratorP(b.begin(), itSize);
	VIteratorP	bEnd = VIteratorP(b.end(), itSize);
	size_t		k = 3;
	size_t		bFrom = 0;
	size_t		bTo = 2;
	size_t		bSize = (b.size() / itSize);
	// std::cout << BOLD "----- MAIN LOOP -----" RESET << std::endl;
	while (true)
	{
		bFrom = getJacobsthalNumber(k);
		// std::cout << "bFrom = " << bFrom << std::endl;
		// std::cout << "bSize + 2 = " << bSize + 2  << std::endl;
		if (bFrom >= bSize + 2)
			break ;

		for (size_t i = bFrom + 1; i > bTo; )
		{
			--i;
			// std::cout << "b" << i << std::endl;
			// std::cout << GREEN "Insert " RESET ITALIC BOLD "b" << i << RESET << std::endl;
			aBegin = a.begin();
			aEnd = a.end();
			bBegin = b.begin();
			bEnd = b.end();
			VIteratorP	aN = findXN(aBegin, aEnd, i);
			// std::cout << aN->first << std::endl;///////
			// std::cout << "range = " << std::distance(aBegin, aN) << std::endl;///////
			VIteratorP	bN = findXN(bBegin, bEnd, i);
			VIteratorP	position = binarySearchIndex(aBegin, aN, bN->first);
			// Let's see if this works for now, I'm not sure i I might have to set
			// the used VIteratorP indexes to 0 after insertion or something
			// VIteratorP position = std::lower_bound(aBegin, aN, bN, compareCustom); // try this too
			// std::cout << "Inserting: " << bN->first << " at position: " << position->first << std::endl;
			// printInsertion(a, position, bN);
			insertVIteratorP(a, position, bN);
		}
		bTo = bFrom + 1;
		++k;
	}
	// std::cout << BOLD "----- SECONDARY LOOP -----" RESET << std::endl;
	// std::cout << "bTo = " << bTo << std::endl;
	// std::cout << "bSize + 2 = " << bSize + 2 << std::endl;
	size_t i = bTo;
	while (i < bSize + 2)
	{
		// std::cout << GREEN "Insert " RESET ITALIC BOLD "b" << i << RESET << std::endl;

		aBegin = a.begin();
		aEnd = a.end();
		bBegin = b.begin();
		bEnd = b.end();
		VIteratorP	aN = findXN(aBegin, aEnd, i);
		VIteratorP	bN = findXN(bBegin, bEnd, i);
		// VIteratorP	aEnd = VIteratorP(a.end(), itSize);
		// VIteratorP	position = std::lower_bound(aBegin, aEnd, bN, compareCustom);
		VIteratorP	position = binarySearchIndex(aBegin, aN, bN->first);
		// printInsertion(a, position, bN);
		insertVIteratorP(a, position, bN);
		++i;
	}
	if (oddElement)
	{
		aBegin = a.begin();
		aEnd = a.end();
		// std::cout << "odd:" << std::endl;
		VIteratorP	position = binarySearchIndex(aBegin, aEnd, (*oddElement)->first); 
		insertVIteratorP(a, position, *oddElement);
	}
	// std::cout << BOLD "======== INSERT ELEMENTS DONE ========" RESET << std::endl;
}

static void	mergeChain(VIteratorP first, VIteratorP last, std::vector<std::pair<unsigned int, unsigned int> > & a)
{
	std::copy(a.begin(), a.end(), first.base());
	for (VIteratorP it = first; it != last; ++it)
		it->second = 0;
}

void	PmergeMe::mergeInsertionSort( VIteratorP first, VIteratorP last )
{
	// std::cout << "in----" << std::endl;
	// std::cout << BOLD "========== MERGE INSERTION SORT ==========" RESET << std::endl;
	size_t	size = std::distance(first, last);
	if (size < 2)
	{
		// std::cout << "out---" << std::endl;
		// std::cout << BOLD "========== MERGE INSERTION SORT DONE ==========" RESET << std::endl;
		return ;
	}
	bool			isSizeOdd = size % 2 != 0;
	VIteratorP		end = isSizeOdd ? last - 1 : last;
	VIteratorP *	oddElement = isSizeOdd ? &end : NULL;
	VIteratorP &	start = first;
	size_t			itSize = first.size();

	// std::cout << "Enters" << std::endl;
	// printChain(first, last, "V");

	sortAdjacentPairs(start, end);

	// std::cout << "sortAdjacentPairs" << std::endl;
	// printChain(start, end, "V");

	if (size >= 4)
		mergeInsertionSort(VIteratorP(start, itSize * 2), VIteratorP(end, itSize * 2));

	// std::cout << "After recurssion" << std::endl;
	// printChain(start, end, "V");

	std::vector<std::pair<unsigned int, unsigned int> >	a;
	std::vector<std::pair<unsigned int, unsigned int> >	b;
	a.reserve(size);
	b.reserve(size);
	initialiseChains(start, end, a, b);

	// std::cout << "Chains A and B initialised to:" << std::endl;
	// printChain(VIteratorP(a.begin(), itSize), VIteratorP(a.end(), itSize), "A");
	// printChain(VIteratorP(b.begin(), itSize), VIteratorP(b.end(), itSize), "B");

	insertElements(a, b, itSize, oddElement);


	mergeChain(start, last, a);
	
	// std::cout << "After insertion" << std::endl;
	// printChain(start, last, "V");

		// std::cout << "out---" << std::endl;
	// std::cout << BOLD "========== MERGE INSERTION SORT DONE ==========" RESET << std::endl;
}