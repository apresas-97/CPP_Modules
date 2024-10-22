#include "LIterator.hpp"

LIterator::LIterator( void ) {}

LIterator::LIterator( iterator_type it, size_t size ) : _it(it), _size(size) {}

LIterator::LIterator( iterator_type it ) : _it(it), _size(1) {}

LIterator::LIterator( LIterator it, size_t size ) : _it(it.base()), _size(size) {}

LIterator::LIterator( LIterator const & other ) : _it(other.base()), _size(other.size()) {}

LIterator::~LIterator() {}

//// Member functions
// returns the underlying iterator
LIterator::iterator_type	LIterator::base( void ) const
{
	return _it;
}

// returns the size of the LIterator
// LIterator::difference_type	LIterator::size( void ) const
size_t	LIterator::size( void ) const
{
	return _size;
}

////// Operators
// Assigns the underlying iterator of another LIterator to this LIterator of equal size
LIterator &	LIterator::operator=( LIterator const & other )
{
	if (this != &other && _size == other.size())
		_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the LIterator is pointing to
LIterator::reference	LIterator::operator*( void ) const
{
	LIterator	tmp(_it, 1);
	tmp += _size - 1;
	return *tmp.base();
}

// Returns the address of the meaningful value that the LIterator is pointing to
LIterator::pointer		LIterator::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the LIterator by index
LIterator::value_type	LIterator::operator[]( size_t index )
{
	LIterator	tmp(_it, 1);
	tmp += (index * _size + _size - 1);
	return *tmp.base();
}

// Accesses the meaningful value from the LIterator by index, const version
LIterator::value_type	LIterator::operator[]( size_t index ) const
{
	LIterator	tmp(_it, 1);
	tmp += (index * _size + _size - 1);
	return *tmp.base();
}

//// Increment and Decrement operators
// Advances the LIterator by _size
LIterator &	LIterator::operator++( void )
{
	// for (size_t i = 0; i < _size; i++)
		// _it++;
	std::advance(_it, _size);
	return *this;
}

// Advances the LIterator by _size, post increment
LIterator	LIterator::operator++( int )
{
	LIterator tmp(*this);
	// for (size_t i = 0; i < _size; i++)
		// _it++;
	std::advance(_it, _size);
	return tmp;
}

// Decrements the LIterator by _size
LIterator &	LIterator::operator--( void )
{
	// for (size_t i = 0; i < _size; i++)
		// _it--;
	std::advance(_it, -_size);
	return *this;
}

// Decrements the LIterator by _size, post decrement
LIterator	LIterator::operator--( int )
{
	LIterator tmp(*this);
	// for (size_t i = 0; i < _size; i++)
		// _it--;
	std::advance(_it, -_size);
	return tmp;
}

// Advances the LIterator by _size * increment
LIterator &	LIterator::operator+=( difference_type increment )
{
	// for (size_t i = 0; i < _size; i++)
	// 	for (long j = 0; j < increment; j++)
	// 		_it++;
	std::advance(_it, _size * increment);
	return *this;
}

// Decrements the LIterator by _size * decrement
LIterator &	LIterator::operator-=( difference_type decrement )
{
	// for (size_t i = 0; i < _size; i++)
	// 	for (long j = 0; j < decrement; j++)
	// 		_it--;
	std::advance(_it, -_size * decrement);
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two LIterators
bool	LIterator::operator==( LIterator const & rhs ) const
{
	return _it == rhs.base();
}

bool	LIterator::operator!=( LIterator const & rhs ) const
{
	return _it != rhs.base();
}

// bool	LIterator::operator<( LIterator const & rhs ) const
// {
// 	return _it < rhs.base();
// }

// bool	LIterator::operator<=( LIterator const & rhs ) const
// {
// 	return _it <= rhs.base();
// }

// bool	LIterator::operator>( LIterator const & rhs ) const
// {
// 	return _it > rhs.base();
// }

// bool	LIterator::operator>=( LIterator const & rhs ) const
// {
// 	return _it >= rhs.base();
// }

//// Arithmetic operators
// Advances the LIterator by increment * _size
LIterator	LIterator::operator+( difference_type increment )
{
	LIterator it(_it, _size);
	it += increment;
	return it;
}

// Decrements the LIterator by decrement * _size
LIterator	LIterator::operator-( difference_type decrement )
{
	LIterator it(_it, _size);
	it -= decrement;
	return it;
}

// // Returns the difference between the underlying iterators of two LIterators
// LIterator::difference_type	LIterator::operator-( LIterator const & rhs ) const
// {
// 	return (_it - rhs.base()) / _size;
// }

// For LIteratorUtils.cpp ??
// Swaps the contents of two LIterators
void	swapLIterator( LIterator lhs, LIterator rhs )
{
	size_t	size = lhs.size();
	std::list<unsigned int>::iterator lhsIt = lhs.base();
	std::list<unsigned int>::iterator rhsIt = rhs.base();
	for (size_t i = 0; i < size; i++)
	{
		std::iter_swap(lhsIt, rhsIt);
		lhsIt++;
		rhsIt++;
	}
}

void	printLIterator( LIterator start, LIterator end )
{
	if (start.size() == 1)
	{
		for (LIterator it = start; it != end; it++)
		{
			std::cout << it[0] << " ";
		}
		std::cout << std::endl;
		return ;
	}
	std::stringstream ss0;
	std::stringstream ss1;
	for (LIterator it = start; it != end; it++)
	{
		LIterator::iterator_type tmp = it.base();
		ss0 << " ";
		ss1 << "[";
		for (size_t k = 0; k < it.size(); k++)
		{
			if (*tmp == *it)
				ss0 << "v";
			else
				ss0 << " ";
			ss1 << *tmp;
			if (k + 1 < it.size())
			{
				ss0 << "  ";
				ss1 << ", ";	
			}
			tmp++;
		}
		ss0 << " ";
		ss1 << "]";
	}
	std::cout << ss0.str() << std::endl;
	std::cout << ss1.str() << std::endl;
	std::cout << std::endl;
}
