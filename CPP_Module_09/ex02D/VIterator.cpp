#include "VIterator.hpp"

VIterator::VIterator( void )
{
	throw std::exception();// for now
	// _it = NULL;
	// _size = 0;
}

VIterator::VIterator( iterator_type it, size_t size ) : _it(it), _size(size)
{
	
}

VIterator::VIterator( VIterator it, size_t size ) : _it(it.base()), _size(size)
{
	
}

VIterator::VIterator( VIterator const & other )
{
	*this = other;
}

VIterator::~VIterator()
{
	
}

VIterator &	VIterator::operator=( VIterator const & other )
{
	if (this != &other)
	{
		_it = other.base();
		_size = other.size();
	}
	return *this;
}

// Member functions
VIterator::iterator_type	VIterator::base( void ) const
{
	return _it;
}

VIterator::difference_type	VIterator::size( void ) const
{
	return _size;
}

// Operators
VIterator::reference	VIterator::operator*( void ) const
{
	return *(_it + _size - 1);
}

VIterator::pointer		VIterator::operator->( void ) const
{
	return &(operator*());
}

VIterator::value_type	VIterator::operator[]( size_t index )
{
	return _it[index * _size + _size - 1];
}

VIterator::value_type	VIterator::operator[]( size_t index ) const
{
	return _it[index * _size + _size - 1];
}
//
VIterator &	VIterator::operator++( void )
{
	_it += _size;
	return *this;
}

VIterator	VIterator::operator++( int )
{
	VIterator tmp(*this);
	_it += _size;
	return tmp;
}

VIterator &	VIterator::operator--( void )
{
	_it -= _size;
	return *this;
}

VIterator	VIterator::operator--( int )
{
	VIterator tmp(*this);
	_it -= _size;
	return tmp;
}

VIterator &	VIterator::operator+=( difference_type increment )
{
	_it += increment * _size;
	return *this;
}

VIterator &	VIterator::operator-=( difference_type decrement )
{
	_it -= decrement * _size;
	return *this;
}
//
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

VIterator	VIterator::operator+( difference_type increment )
{
	VIterator it(_it, _size);
	it += increment;
	return it;
}

VIterator	VIterator::operator-( difference_type decrement )
{
	VIterator it(_it, _size);
	it -= decrement;
	return it;
}

// VIterator::difference_type	VIterator::operator-( VIterator const & rhs ) const
// {
// 	return (_it.base() - rhs.base()) / _size;
// }

// VIterator::difference_type	VIterator::operator+( VIterator const & rhs ) const
// {
// 	return (_it.base() + rhs.base()) / _size;
// }

VIterator::iterator_type	VIterator::base( void ) const
{
	return _it;
}

VIterator::difference_type	VIterator::size( void ) const
{
	return _size;
}

void	swapVIterator( VIterator lhs, VIterator rhs )
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

void	makePairs( VIterator & start, VIterator & end )
{
	for (VIterator it = start; it != end; it++)
	{
		if (it[0] > it[1]) // Make sure this is really correct
			swapVIterator(it, it + 1);
	}
}