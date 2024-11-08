#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_elements_count[VECTOR] = 0;
	this->_elements_count[LIST] = 0;
	this->_time_elapsed[VECTOR] = 0.0;
	this->_time_elapsed[LIST] = 0.0;
	this->_time_start[VECTOR] = 0.0;
	this->_time_start[LIST] = 0.0;
	this->_time_unit = "ms";
	this->_time_multiplier = 1.0;
	this->_time_set[VECTOR] = false;
	this->_time_set[LIST] = false;
}

PmergeMe::PmergeMe( PmergeMe const &other )
{
	this->_elements_count[VECTOR] = 0;
	this->_elements_count[LIST] = 0;
	this->_time_elapsed[VECTOR] = 0.0;
	this->_time_elapsed[LIST] = 0.0;
	this->_time_start[VECTOR] = 0.0;
	this->_time_start[LIST] = 0.0;
	this->_time_unit = "ms";
	this->_time_multiplier = 1.0;
	this->_time_set[VECTOR] = false;
	this->_time_set[LIST] = false;
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other ) { }
	return *this;
}
