#include "PmergeMe.hpp"

// void	mergeLIteratorToList( LIterator start, LIterator end, std::list<unsigned int> & lst )
// {
// 	std::list<unsigned int>	cache;
// 	for (LIterator it = start; it != end; it++)
// 	{
// 		std::list<unsigned int>::iterator begin = it.base();
// 		std::list<unsigned int>::iterator end = begin;
// 		std::advance(end, it.size());
// 		while (begin != end)
// 		{
// 			cache.push_back(*begin);
// 			begin++;
// 		}
// 	}
// 	std::swap_ranges(cache.begin(), cache.end(), lst.begin());
// }

void	PmergeMe::mergeIteratorToContainer( LIterator start, LIterator end, std::list<unsigned int>::iterator lstart )
{
	std::list<unsigned int>	cache;
	for (LIterator it = start; it != end; it++)
	{
		std::list<unsigned int>::iterator begin = it.base();
		std::list<unsigned int>::iterator end = begin;
		std::advance(end, it.size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), lstart);
}

// void	mergeVIteratorToVector( VIterator start, VIterator end, std::vector<unsigned int> & vec )
// {
// 	std::vector<unsigned int>	cache;
// 	cache.reserve(vec.size());
// 	for (VIterator it = start; it != end; it++)
// 	{
// 		std::vector<unsigned int>::iterator begin = it.base();
// 		std::vector<unsigned int>::iterator end = begin + it.size();
// 		while (begin != end)
// 		{
// 			cache.push_back(*begin);
// 			begin++;
// 		}
// 	}
// 	std::swap_ranges(cache.begin(), cache.end(), vec.begin());
// }

void	PmergeMe::mergeIteratorToContainer( VIterator start, VIterator end, std::vector<unsigned int>::iterator vstart )
{
	std::vector<unsigned int>	cache;
	cache.reserve(end - start);
	for (VIterator it = start; it != end; it++)
	{
		std::vector<unsigned int>::iterator begin = it.base();
		std::vector<unsigned int>::iterator end = begin + it.size();
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), vstart);
}
