#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

// Merge Insertion Sort for std::vector<unsigned int> // PUBLIC
void	PmergeMe::mergeInsertionSort( std::vector<unsigned int> & vec )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = vec.size();
	if (vec.size() < 2)
		return ;
	std::clock_t	timeStart = std::clock();

	VIterator		start(vec.begin());
	VIterator		end(vec.end());
	mergeInsertionSort(vec.begin(), vec.end());
	mergeIteratorToContainer(start, end, vec.begin());
	this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

// // Merge Insertion Sort for std::vector iterator range // PUBLIC
// void	PmergeMe::mergeInsertionSort( std::vector<unsigned int>::iterator first, std::vector<unsigned int>::iterator last )
// {
// 	this->_timeElapsed[VECTOR] = 0.0;
// 	if (std::distance(first, last) < 2)
// 		return ;
// 	this->_elementsCount[VECTOR] = std::distance(first, last);

// 	std::clock_t	timeStart = std::clock();
// 	VIterator		start(first);
// 	VIterator		end(last);
// 	std::cout << "--------------------------------------------------" << std::endl;
// 	std::cout << "VECTOR MERGE INSERTION SORT START" << std::endl;
// 	std::cout << "--------------------------------------------------" << std::endl;
// 	mergeInsertionSortImpl<VIterator>(start, end);
// 	mergeIteratorToContainer(start, end, first);
// 	this->_timeElapsed[VECTOR] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
// 	std::cout << "--------------------------------------------------" << std::endl;
// 	std::cout << "VECTOR MERGE INSERTION SORT END" << std::endl;
// 	std::cout << "--------------------------------------------------" << std::endl;
// }

// Merge Insertion Sort for std::list
void	PmergeMe::mergeInsertionSort( std::list<unsigned int> & lst )
{
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[LIST] = lst.size();
	if (lst.size() < 2)
		return ;
	std::clock_t		timeStart = std::clock();
	LIterator<uint_t>	start(lst.begin());
	LIterator<uint_t>	end(lst.end());
	mergeInsertionSort(start, end);
	mergeIteratorToContainer(start, end, lst.begin());
	this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
}

// // Merge Insertion Sort for std::list iterator range // PUBLIC
// void	PmergeMe::mergeInsertionSort( std::list<unsigned int>::iterator first, std::list<unsigned int>::iterator last )
// {
// 	this->_timeElapsed[LIST] = 0.0;
// 	if (std::distance(first, last) < 2)
// 		return ;
// 	this->_elementsCount[LIST] = std::distance(first, last);

// 	std::clock_t	timeStart = std::clock();
// 	LIterator		start(first);
// 	LIterator		end(last);
// 	std::cout << "--------------------------------------------------" << std::endl;
// 	std::cout << "LIST MERGE INSERTION SORT START" << std::endl;
// 	std::cout << "--------------------------------------------------" << std::endl;
// 	mergeInsertionSortImpl(start, end);
// 	// mergeInsertionSortImpl<LIterator>(start, end);
// 	mergeIteratorToContainer(start, end, first);
// 	this->_timeElapsed[LIST] = (double)(std::clock() - timeStart) / CLOCKS_PER_SEC;
// }
