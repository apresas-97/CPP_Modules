#include "VIteratorP.hpp"

VIteratorP::VIteratorP( void ) {}

VIteratorP::VIteratorP( iterator_type it, size_t size ) : _it(it), _size(size) {}

VIteratorP::VIteratorP( iterator_type it ) : _it(it), _size(1) {}

VIteratorP::VIteratorP( VIteratorP it, size_t size ) : _it(it.base()), _size(size) {}

VIteratorP::VIteratorP( VIteratorP const & other ) : _it(other.base()), _size(other.size()) {}

VIteratorP::~VIteratorP() {}

//// Member functions
// returns the underlying iterator
VIteratorP::iterator_type	VIteratorP::base( void ) const
{
	return _it;
}

VIteratorP::iterator_type	VIteratorP::end( void ) const
{
	return _it + _size;
}

// returns the size of the VIteratorP
// VIteratorP::difference_type	VIteratorP::size( void ) const
size_t	VIteratorP::size( void ) const
{
	return _size;
}

unsigned int	VIteratorP::value( void )
{
	return _it[_size - 1].first;
}

unsigned int	VIteratorP::index( void )
{
	return _it[_size - 1].second;
}

////// Operators
// Assigns the underlying iterator of another VIteratorP to this VIteratorP of equal size
VIteratorP &	VIteratorP::operator=( VIteratorP const & other )
{
	if (this != &other && _size == other.size())
		_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the VIteratorP is pointing to
VIteratorP::reference	VIteratorP::operator*( void ) const
{
	return _it[_size - 1];
}

// Returns the address of the meaningful value that the VIteratorP is pointing to
VIteratorP::pointer		VIteratorP::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the VIteratorP by index
VIteratorP::value_type	VIteratorP::operator[]( size_t index )
{
	return _it[index * _size + _size - 1];
}

// Accesses the meaningful value from the VIteratorP by index, const version
VIteratorP::value_type	VIteratorP::operator[]( size_t index ) const
{
	return _it[index * _size + _size - 1];
}

//// Increment and Decrement operators
// Advances the VIteratorP by _size
VIteratorP &	VIteratorP::operator++( void )
{
	_it += _size;
	return *this;
}

// Advances the VIteratorP by _size, post increment
VIteratorP	VIteratorP::operator++( int )
{
	VIteratorP tmp(*this);
	_it += _size;
	return tmp;
}

// Decrements the VIteratorP by _size
VIteratorP &	VIteratorP::operator--( void )
{
	_it -= _size;
	return *this;
}

// Decrements the VIteratorP by _size, post decrement
VIteratorP	VIteratorP::operator--( int )
{
	VIteratorP tmp(*this);
	_it -= _size;
	return tmp;
}

// Advances the VIteratorP by _size * increment
VIteratorP &	VIteratorP::operator+=( difference_type increment )
{
	_it += increment * _size;
	return *this;
}

// Decrements the VIteratorP by _size * decrement
VIteratorP &	VIteratorP::operator-=( difference_type decrement )
{
	_it -= decrement * _size;
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two VIteratorPs
bool	VIteratorP::operator==( VIteratorP const & rhs ) const
{
	return _it == rhs.base();
}

bool	VIteratorP::operator!=( VIteratorP const & rhs ) const
{
	return _it != rhs.base();
}

bool	VIteratorP::operator<( VIteratorP const & rhs ) const
{
	return _it < rhs.base();
}

bool	VIteratorP::operator<=( VIteratorP const & rhs ) const
{
	return _it <= rhs.base();
}

bool	VIteratorP::operator>( VIteratorP const & rhs ) const
{
	return _it > rhs.base();
}

bool	VIteratorP::operator>=( VIteratorP const & rhs ) const
{
	return _it >= rhs.base();
}

//// Arithmetic operators
// Advances the VIteratorP by increment * _size
VIteratorP	VIteratorP::operator+( difference_type increment )
{
	VIteratorP it(_it, _size);
	it += increment;
	return it;
}

// Decrements the VIteratorP by decrement * _size
VIteratorP	VIteratorP::operator-( difference_type decrement )
{
	VIteratorP it(_it, _size);
	it -= decrement;
	return it;
}

// Returns the difference between the underlying iterators of two VIteratorPs
VIteratorP::difference_type	VIteratorP::operator-( VIteratorP const & rhs ) const
{
	return (_it - rhs.base()) / _size;
}

// // For VIteratorPUtils.cpp ??
// // Swaps the contents of two VIteratorPs
// void	swapVIteratorP( VIteratorP lhs, VIteratorP rhs )
// {
// 	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
// }

// void	printVIteratorP( VIteratorP start, VIteratorP end )
// {
// 	if (start.size() == 1)
// 	{
// 		for (VIteratorP it = start; it != end; it++)
// 		{
// 			std::cout << it[0] << " ";
// 		}
// 		std::cout << std::endl;
// 		return ;
// 	}
// 	std::ostringstream oss0;
// 	std::ostringstream oss1;
// 	for (VIteratorP it = start; it != end; it++)
// 	{
// 		typename VIteratorP::iterator_type tmp = it.base();
// 		oss0 << " ";
// 		oss1 << "[";
// 		for (size_t k = 0; k < it.size(); k++)
// 		{
// 			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
// 				oss0 << " ";
// 			if (*tmp == *it)
// 				oss0 << "v";
// 			else
// 				oss0 << " ";
// 			oss1 << *tmp;
// 			if (k + 1 < it.size())
// 			{
// 				oss0 << "  ";
// 				oss1 << ", ";
// 			}
// 			tmp++;
// 		}
// 		oss0 << " ";
// 		oss1 << "]";
// 	}
// 	std::cout << oss0.str() << std::endl;
// 	std::cout << oss1.str() << std::endl;
// 	std::cout << std::endl;
// }

