#include "PmergeMe.hpp"

// // Binary search function for std::vector sorting
// VIteratorList::iterator	PmergeMe::binarySearch(VIteratorList::iterator left, VIteratorList::iterator right, unsigned int val )
// {
// 	VIteratorList::iterator											mid;
// 	std::iterator_traits<VIteratorList::iterator>::difference_type	search_range;
// 	std::iterator_traits<VIteratorList::iterator>::difference_type	half_range;

// 	search_range = std::distance(left, right);
// 	while (search_range > 0)
// 	{
// 		mid = left;
// 		half_range = search_range / 2;
// 		std::advance (mid, half_range);
// 		if (!(val < **mid))
// 		{
// 			mid++;
// 			left = mid;
// 			search_range -= half_range + 1;
// 		}
// 		else
// 			search_range = half_range;
// 	}
// 	return left;
// }

// // Binary search function for std::list sorting
// LIteratorList::iterator	PmergeMe::binarySearch(LIteratorList::iterator left, LIteratorList::iterator right, unsigned int val )
// {
// 	LIteratorList::iterator											mid;
// 	std::iterator_traits<LIteratorList::iterator>::difference_type	search_range;
// 	std::iterator_traits<LIteratorList::iterator>::difference_type	half_range;

// 	search_range = std::distance(left, right);
// 	while (search_range > 0)
// 	{
// 		mid = left;
// 		half_range = search_range / 2;
// 		std::advance (mid, half_range);
// 		if (!(val < **mid))
// 		{
// 			mid++;
// 			left = mid;
// 			search_range -= half_range + 1;
// 		}
// 		else
// 			search_range = half_range;
// 	}
// 	return left;
// }
