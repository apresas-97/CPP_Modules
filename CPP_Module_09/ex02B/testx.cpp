#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

void	printVector( std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t elementSize )
{
	std::vector<int>::iterator	it = begin;
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << *it << " -> ";
		else
			std::cout << *it;
		it += elementSize;
	}
	std::cout << std::endl;
}

void	printCute( std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t elementSize )
{
	std::vector<int>::iterator	it = begin + elementSize / 2;
	std::cout << "a: ";
	while (it < end)
	{
		if (it + elementSize < end)
			std::cout << *it << " --> ";
		else
			std::cout << *it;
		it += elementSize;
	}
	std::cout << std::endl;
	if (elementSize == 1)
		return;
	std::cout << "    ";
	it = begin;
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << "\\     ";
		it += elementSize;
	}
	std::cout << std::endl;
	it = begin;
	std::cout << "     ";
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << "\\     ";
		it += elementSize;
	}
	std::cout << std::endl;
	it = begin;
	std::cout << "b:    ";
	while (it < end)
	{
		if (it + elementSize < end)
			std::cout << *it << "     ";
		else
			std::cout << *it;
		it += elementSize;
	}
	std::cout << std::endl;
}

template<typename Iterator, typename Comparator>
void	sortPair( Iterator pairA, Iterator pairB, Comparator comp, size_t elementSize )
{
	if (comp(*pairA, *pairB))
	{
		for (size_t i = 0; i < elementSize; i++)
			std::swap(*(pairA + i), *(pairB + i));
	}
}

size_t	jacobsthalNumber( size_t k )
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;

	size_t	a = 0;
	size_t	b = 1;
	size_t	c;
	for (size_t i = 2; i <= k; i++)
	{
		c = 2 * b + a;
		a = b;
		b = c;
	}
	return b;
}

template<typename Iterator>
Iterator	binarySearch( Iterator begin, Iterator end, Iterator element, size_t elementSize )
{
	Iterator	start = begin;
	while (start < end)
	{
		Iterator	mid = start + std::distance(start, end) / 2;

		if (*mid == *element)
			return mid;
		else if (*mid < *element)
			start = mid + elementSize;
		else
			end = mid - elementSize;
	}
	return end;
}

void	insertElement( std::vector<int> & vec, std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int>::iterator element, size_t elementSize )
{
	std::cout << "InsertElement called" << std::endl;
	// std::cout << " >>elementSize = " << elementSize << std::endl;
	// std::cout << " >>Iterator begin = " << *begin << std::endl;
	// std::cout << " >>Iterator end = " << *end << std::endl;
	// std::cout << " >>Iterator element = " << *element << std::endl;

	std::vector<int>::iterator	insertPos = binarySearch(begin, end, element, elementSize);
	// std::cout << " >>Iterator insertPos = " << *insertPos << std::endl;
	size_t	insertIndex = std::distance(begin, insertPos);
	// std::cout << " >>insertIndex = " << insertIndex << std::endl;

	std::cout << "Vector before insertion:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);

	for (size_t i = 0; i < elementSize; i++)
	{
		std::cout << "Inserting " << *(element + i) << std::endl;
		std::cout << "Inserting at " << insertIndex << std::endl;
		vec.insert(vec.begin() + insertIndex, *(element + i));
		insertIndex++;
	}
	
	std::cout << "Vector after insertion:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);
}

//
size_t	binarySearch( std::vector<int> & vec, size_t begin, size_t end, int element, size_t elementSize )
{
	while (begin < end)
	{
		size_t	mid = begin + (end - begin) / 2;

		if (vec[mid] == element)
			return mid;
		else if (vec[mid] > element)
		// else if (vec[mid] < element) // Which one?
			begin = mid + elementSize;
		else
			end = mid - elementSize;
	}
	return end;
}
//
void	insertElement( std::vector<int> & vec, size_t begin, size_t end, std::vector<int> & elementVec, size_t element, size_t elementSize )
{
	std::cout << "InsertElement called" << std::endl;
	// std::cout << " >>elementSize = " << elementSize << std::endl;
	// std::cout << " >>Iterator begin = " << begin << std::endl;
	// std::cout << " >>Iterator end = " << end << std::endl;
	// std::cout << " >>Iterator element = " << *element << std::endl;

	size_t	insertPos = binarySearch(vec, begin, end, elementVec[element], elementSize);
	std::cout << " >>Iterator insertPos = " << insertPos << std::endl;

	std::cout << "Vector before insertion:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);

	for (size_t i = 0; i < elementSize; i++)
	{
		std::cout << "Inserting " << elementVec[element + i] << std::endl;
		std::cout << "Inserting at " << insertPos << std::endl;
		vec.insert(vec.begin() + insertPos, elementVec[element + i]);
		insertPos++;
	}
	
	std::cout << "Vector after insertion:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);
}

template<typename Iterator>
std::vector<int>	getMainChain( Iterator begin, Iterator end, size_t elementSize )
{
	std::cout << "getMainChain called" << std::endl;
	std::cout << " >>elementSize = " << elementSize << std::endl;
	std::cout << " >>Iterator begin = " << *begin << std::endl;
	std::cout << " >>Iterator end = " << *end << std::endl;

	std::vector<int>	mainChain;
	Iterator			it = begin;

	while (it < end)
	{
		if (it + elementSize > end)
			break ;
		for (size_t i = 0; i < elementSize; i++)
		{
			std::cout << "push_back " << *(it + i) << std::endl;
			mainChain.push_back(*(it + i));
		}
		it += 2 * elementSize;
	}
	return mainChain;
}

template<typename Iterator>
std::vector<int>	getPend( Iterator begin, Iterator end, size_t elementSize )
{
	std::cout << "getPend called" << std::endl;
	std::cout << " >>elementSize = " << elementSize << std::endl;
	std::vector<int>	pend;
	Iterator			it = begin + elementSize;
	std::cout << " >>Iterator begin = " << *it << std::endl;
	std::cout << " >>Iterator end = " << *end << std::endl;

	while (it < end)
	{
		if (it + elementSize > end)
			break ;
		for (size_t i = 0; i < elementSize; i++)
		{
			std::cout << "push_back " << *(it + i) << std::endl;
			pend.push_back(*(it + i));
		}
		it += 2 * elementSize;
	}
	return pend;
}

template<typename Iterator>
void	mergeInsertionSort( Iterator begin, Iterator end, size_t elementSize )
{
	std::cout << "MergeInsertionSort" << std::endl;

	size_t	size = std::distance(begin, end) / elementSize;
	std::cout << "Size = " << size << std::endl;
	std::cout << "elementSize = " << elementSize << std::endl;
	if (size < 2) // Maybe?
		return ;
	
	std::cout << "Received vector:" << std::endl;
	printCute(begin, end, elementSize);

	// Do something about the odd element?
	bool		oddSize = (size % 2 != 0);
	Iterator	lastValue;
	if (oddSize)
	{
		lastValue = end - elementSize;
		end -= elementSize;
	}
	// Iterator	rEnd = oddSize ? end - elementSize : end;

	// printCute(begin, end, elementSize);

	// Create "pairs"
	size_t	nbPairs = size / 2;
	size_t	pairSize = elementSize * 2;
	// std::cout << " >oddSize = " << oddSize << std::endl;
	// std::cout << " >elementSize = " << elementSize << std::endl;
	// std::cout << " >size = " << size << std::endl;
	// std::cout << " >nbPairs = " << nbPairs << std::endl;
	// std::cout << " >pairSize = " << pairSize << std::endl;


	// std::cout << "Vector on entry" << std::endl;
	// printVector(begin, end, elementSize);
	// std::cout << "True Vector on entry" << std::endl;
	// printVector(begin, end, 1);
	// Sort "pairs"
	for (Iterator it = begin; it != end; it += pairSize)
		sortPair(it, it + elementSize, std::less<int>(), elementSize);
	std::cout << "After sortPair" << std::endl;
	printCute(begin, end, elementSize);
	std::cout << "Leftover: " << std::endl;
	printCute(lastValue, lastValue + elementSize, elementSize);
	// std::cout << "True After sortPair" << std::endl;
	// printVector(begin, end, 1);

	// Sort the "pairs" by their first element, recursively
	// if (nbPairs > 1)
		mergeInsertionSort(begin, begin + (nbPairs * pairSize), pairSize);
	std::cout << "Check Recursion OUT" << std::endl;

	std::cout << "Vector after recursion" << std::endl;
	printCute(begin, end, elementSize);
	// std::cout << "True Vector after recursion" << std::endl;
	// printVector(begin, end, 1);

	// std::vector<int>	mainChain = getMainChain(begin, end, elementSize);
	// std::vector<int>	pend = getPend(begin, end, elementSize);
	std::vector<int>	mainChain = getPend(begin, end, elementSize);
	std::vector<int>	pend = getMainChain(begin, end, elementSize);
	std::cout << std::endl;

	size_t	k = 3; // jacobsthal index
	size_t	i = 0; // pend index
	size_t	pendEnd = 0;
	// mainChain.insert(mainChain.begin(), pend[i]); // insert b1
	// mainChain.insert(mainChain.begin(), pend[0]);
	// insertElement(mainChain, 0, 0, pend, 0, elementSize);
	insertElement(mainChain, mainChain.begin(), mainChain.begin(), pend.begin(), elementSize);
	size_t	insertedElements = 1;
	while (true)
	{
		pendEnd = jacobsthalNumber(k - 1) - 1;
		// std::cout << "pendEnd = " << pendEnd << std::endl;
		i = jacobsthalNumber(k) - 1;
		// std::cout << "i = " << i << std::endl;
		// std::cout << "i >= pend.size() = " << (i >= pend.size()) << std::endl;
		if (i >= pend.size()) // start is out of bounds
			break ;
		while (i >= pendEnd)
		{
			insertElement(mainChain, mainChain.begin(), mainChain.begin() + ((i + insertedElements) * elementSize), pend.begin() + i, elementSize);
			// I should find the correct range to insert the element
			i--;
		}
		k++;
	}

	// std::cout << "Check out of main loop" << std::endl;

	// The target index was out of bounds
	// We insert the remaining pend elements, but first we must insert the odd element if there was one
	if (oddSize)
		insertElement(mainChain, mainChain.begin(), mainChain.end(), lastValue, elementSize);
	// std::cout << "Check lastValue inserted" << std::endl;
	for (size_t i = pend.size() - 1; i >= pendEnd; i--)
	{
		insertElement(mainChain, mainChain.begin(), mainChain.begin() + i + insertedElements,  pend.begin() + i, elementSize);
		std::cout << "check" << std::endl;
		insertedElements++;
	}
	// std::cout << "Check remaining pend inserted" << std::endl;

	std::cout << "Check reached the end" << std::endl;

	Iterator it = begin;
	Iterator ite = end + elementSize;
	size_t	index = 0;
	while (it != ite)
	{
		*it = mainChain[index];
		index++;
		it++;
	}

	return ;
}



int	main( void )
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(6);

	std::cout << "Before:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);

	mergeInsertionSort(vec.begin(), vec.end(), 1);

	std::cout << "Before:" << std::endl;
	printVector(vec.begin(), vec.end(), 1);

	return 0;
}
