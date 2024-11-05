#include "VIterator.hpp"

VIterator::VIterator( void ) {}

VIterator::VIterator( iterator_type it, size_t size ) : _it(it), _size(size) {}

VIterator::VIterator( iterator_type it ) : _it(it), _size(1) {}

VIterator::VIterator( VIterator it, size_t size ) : _it(it.base()), _size(size) {}

VIterator::VIterator( VIterator const & other ) : _it(other.base()), _size(other.size()) {}

VIterator::~VIterator() {}

//// Member functions
// returns the underlying iterator
VIterator::iterator_type	VIterator::base( void ) const
{
	return _it;
}

VIterator::iterator_type	VIterator::end( void ) const
{
	return _it + _size;
}

// returns the size of the VIterator
// VIterator::difference_type	VIterator::size( void ) const
size_t	VIterator::size( void ) const
{
	return _size;
}

////// Operators
// Assigns the underlying iterator of another VIterator to this VIterator of equal size
VIterator &	VIterator::operator=( VIterator const & other )
{
	if (this != &other && _size == other.size())
		_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the VIterator is pointing to
VIterator::reference	VIterator::operator*( void ) const
{
	return _it[_size - 1];
}

// Returns the address of the meaningful value that the VIterator is pointing to
VIterator::pointer		VIterator::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the VIterator by index
VIterator::value_type	VIterator::operator[]( size_t index )
{
	return _it[index * _size + _size - 1];
}

// Accesses the meaningful value from the VIterator by index, const version
VIterator::value_type	VIterator::operator[]( size_t index ) const
{
	return _it[index * _size + _size - 1];
}

//// Increment and Decrement operators
// Advances the VIterator by _size
VIterator &	VIterator::operator++( void )
{
	_it += _size;
	return *this;
}

// Advances the VIterator by _size, post increment
VIterator	VIterator::operator++( int )
{
	VIterator tmp(*this);
	_it += _size;
	return tmp;
}

// Decrements the VIterator by _size
VIterator &	VIterator::operator--( void )
{
	_it -= _size;
	return *this;
}

// Decrements the VIterator by _size, post decrement
VIterator	VIterator::operator--( int )
{
	VIterator tmp(*this);
	_it -= _size;
	return tmp;
}

// Advances the VIterator by _size * increment
VIterator &	VIterator::operator+=( difference_type increment )
{
	_it += increment * _size;
	return *this;
}

// Decrements the VIterator by _size * decrement
VIterator &	VIterator::operator-=( difference_type decrement )
{
	_it -= decrement * _size;
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two VIterators
bool	VIterator::operator==( VIterator const & rhs ) const
{
	return _it == rhs.base();
}

bool	VIterator::operator!=( VIterator const & rhs ) const
{
	return _it != rhs.base();
}

bool	VIterator::operator<( VIterator const & rhs ) const
{
	return _it < rhs.base();
}

bool	VIterator::operator<=( VIterator const & rhs ) const
{
	return _it <= rhs.base();
}

bool	VIterator::operator>( VIterator const & rhs ) const
{
	return _it > rhs.base();
}

bool	VIterator::operator>=( VIterator const & rhs ) const
{
	return _it >= rhs.base();
}

//// Arithmetic operators
// Advances the VIterator by increment * _size
VIterator	VIterator::operator+( difference_type increment )
{
	VIterator it(_it, _size);
	it += increment;
	return it;
}

// Decrements the VIterator by decrement * _size
VIterator	VIterator::operator-( difference_type decrement )
{
	VIterator it(_it, _size);
	it -= decrement;
	return it;
}

// Returns the difference between the underlying iterators of two VIterators
VIterator::difference_type	VIterator::operator-( VIterator const & rhs ) const
{
	return (_it - rhs.base()) / _size;
}

// For VIteratorUtils.cpp ??
// Swaps the contents of two VIterators
void	swapVIterator( VIterator lhs, VIterator rhs )
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

void	printVIterator( VIterator start, VIterator end )
{
	if (start.size() == 1)
	{
		for (VIterator it = start; it != end; it++)
		{
			std::cout << it[0] << " ";
		}
		std::cout << std::endl;
		return ;
	}
	std::ostringstream oss0;
	std::ostringstream oss1;
	for (VIterator it = start; it != end; it++)
	{
		typename VIterator::iterator_type tmp = it.base();
		oss0 << " ";
		oss1 << "[";
		for (size_t k = 0; k < it.size(); k++)
		{
			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
				oss0 << " ";
			if (*tmp == *it)
				oss0 << "v";
			else
				oss0 << " ";
			oss1 << *tmp;
			if (k + 1 < it.size())
			{
				oss0 << "  ";
				oss1 << ", ";
			}
			tmp++;
		}
		oss0 << " ";
		oss1 << "]";
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
	std::cout << std::endl;
}

