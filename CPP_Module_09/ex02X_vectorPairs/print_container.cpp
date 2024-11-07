#include "PmergeMe.hpp"
#include <sstream>

void	printVector( vector & vec, std::string prefix )
{
	std::ostringstream oss;
	oss << prefix;
	for (vector::iterator it = vec.begin(); it != vec.end(); it++)
		oss << *it << " ";
	std::cout << oss.str() << std::endl;
}

void	printList( list & lst, std::string prefix )
{
	std::ostringstream oss;
	oss << prefix;
	for (list::iterator it = lst.begin(); it != lst.end(); it++)
		oss << *it << " ";
	std::cout << oss.str() << std::endl;
}
