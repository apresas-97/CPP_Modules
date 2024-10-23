#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_timeElapsed[VECTOR] = 0.0;
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[VECTOR] = 0;
	this->_elementsCount[LIST] = 0;
	initJacobsthalNumbers();
}

PmergeMe::PmergeMe( PmergeMe const &other ) { *this = other; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other ) { }
	return *this;
}

void	PmergeMe::initJacobsthalNumbers( void )
{
	this->_jacobsthalNumbers[0] = 0;
	this->_jacobsthalNumbers[1] = 1;
	for (size_t i = 2; i < 63; i++)
		this->_jacobsthalNumbers[i] = this->_jacobsthalNumbers[i - 1] + 2 * this->_jacobsthalNumbers[i - 2];
}
