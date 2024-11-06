#include "PmergeMe.hpp"

// returns the kth Jacobsthal number
long	jacobsthalNumber( unsigned int k )
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
