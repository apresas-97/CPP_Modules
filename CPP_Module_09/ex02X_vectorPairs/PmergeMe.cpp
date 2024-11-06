#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_elementsCount[VECTOR] = 0;
	this->_elementsCount[LIST] = 0;
	this->_timeElapsed[VECTOR] = 0.0;
	this->_timeElapsed[LIST] = 0.0;
	this->_timeStart[VECTOR] = 0.0;
	this->_timeStart[LIST] = 0.0;
	this->_timeUnit = "ms";
	this->_timeMultiplier = 1.0;
	// initJacobsthalNumbers();
}

PmergeMe::PmergeMe( PmergeMe const &other ) { *this = other; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other ) { }
	return *this;
}

// void	PmergeMe::initJacobsthalNumbers( void )
// {
// 	this->_jacobsthalNumbers[0] = 0;
// 	this->_jacobsthalNumbers[1] = 1;
// 	for (size_t i = 2; i < 63; i++)
// 		this->_jacobsthalNumbers[i] = this->_jacobsthalNumbers[i - 1] + 2 * this->_jacobsthalNumbers[i - 2];
// }

// long	PmergeMe::getJacobsthalNumber( unsigned int k )
// {
// 	if (k == 0)
// 		return 0;
// 	if (k == 1)
// 		return 1;

// 	long	a = 0;
// 	long	b = 1;
// 	long	c;
// 	for (unsigned int i = 2; i <= k; ++i)
// 	{
// 		c = b + 2 * a;
// 		a = b;
// 		b = c;
// 	}
// 	return b;
// }
