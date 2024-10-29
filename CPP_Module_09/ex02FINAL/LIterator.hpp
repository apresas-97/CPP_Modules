#ifndef LITERATOR_HPP
#define LITERATOR_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <list>
#include <sstream>

#define BLOCKS 3
#define VISUALIZER 2
#define TRUE_VECTOR 1
#define DEFAULT 0

typedef unsigned int uint_t;

template<typename T = uint_t>
class LIterator
{
public:

	typedef typename std::iterator_traits<typename std::list<T>::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<typename std::list<T>::iterator>::value_type			value_type;
	typedef typename std::iterator_traits<typename std::list<T>::iterator>::difference_type		difference_type;
	typedef typename std::iterator_traits<typename std::list<T>::iterator>::pointer				pointer;
	typedef typename std::iterator_traits<typename std::list<T>::iterator>::reference			reference;
	typedef typename std::list<T>::iterator													iterator_type;
	typedef std::list<T>																		container_type;

private:

	iterator_type	_it;
	size_t			_size;
	
	LIterator( void );

public:

	LIterator( iterator_type it, size_t size );
	LIterator( iterator_type it );
	LIterator( LIterator it, size_t size );
	LIterator( LIterator const & other );
	~LIterator();

	LIterator &	operator=( LIterator const & other );

	// Member functions
	iterator_type	base( void ) const;
	// difference_type	size( void ) const;
	size_t			size( void ) const;
	value_type		value( void );
	value_type		value( size_t index );
	value_type		value( size_t index ) const;
	iterator_type	next( iterator_type it, size_t n ) const;
	iterator_type	next( iterator_type it, size_t n );
	void			swap( LIterator lhs, LIterator rhs );

	// Operators
	reference		operator*( void ) const;
	pointer			operator->( void ) const;
	value_type		operator[]( size_t index );
	value_type		operator[]( size_t index ) const;

	LIterator &		operator++( void );
	LIterator		operator++( int );
	LIterator &		operator--( void );
	LIterator		operator--( int );
	LIterator &		operator+=( difference_type increment );
	LIterator &		operator-=( difference_type decrement );

	bool			operator==( LIterator const & rhs ) const;
	bool			operator!=( LIterator const & rhs ) const;
	bool			operator<( LIterator const & rhs ) const;
	bool			operator<=( LIterator const & rhs ) const;
	bool			operator>( LIterator const & rhs ) const;
	bool			operator>=( LIterator const & rhs ) const;

	LIterator		operator+( difference_type increment );
	difference_type	operator+( LIterator const & rhs ) const;
	LIterator		operator-( difference_type decrement );
	difference_type	operator-( LIterator const & rhs ) const;

};

void	swapLIterator( LIterator<uint_t> lhs, LIterator<uint_t> rhs );
// void	printLIterator( LIterator<uint_t> start, LIterator<uint_t> end );

template<typename T>
LIterator<T>::LIterator( void ) {}

template<typename T>
LIterator<T>::LIterator( typename LIterator<T>::iterator_type it, size_t size ) : _it(it), _size(size) {}

template<typename T>
LIterator<T>::LIterator( typename LIterator<T>::iterator_type it ) : _it(it), _size(1) {}

template<typename T>
LIterator<T>::LIterator( LIterator<T> it, size_t size ) : _it(it.base()), _size(size) {}

template<typename T>
LIterator<T>::LIterator( LIterator<T> const & other ) : _it(other.base()), _size(other.size()) {}

template<typename T>
LIterator<T>::~LIterator() {}

//// Member functions
// returns the underlying iterator
template<typename T>
typename LIterator<T>::iterator_type	LIterator<T>::base( void ) const
{
	return _it;
}

// returns the value of the meaningul iterator in the LIterator
template<typename T>
typename LIterator<T>::value_type	LIterator<T>::value( void )
{
	return *LIterator::next(_it, _size - 1);
}

// returns the value of the meaningul iterator in the LIterator past the given index
template<typename T>
typename LIterator<T>::value_type	LIterator<T>::value( size_t index )
{
	return *LIterator::next(_it, index * _size + _size - 1);
}

// returns the value of the meaningul iterator in the LIterator past the given index
template<typename T>
typename LIterator<T>::value_type	LIterator<T>::value( size_t index ) const
{
	return *LIterator::next(_it, index * _size + _size - 1);
}

// similar to std::next, but for LIterator, const version
template<typename T>
typename LIterator<T>::iterator_type	LIterator<T>::next( typename LIterator<T>::iterator_type it, size_t n ) const
{
	std::advance(it, n);
	return it;
}

// similar to std::next, but for LIterator
template<typename T>
typename LIterator<T>::iterator_type	LIterator<T>::next( typename LIterator<T>::iterator_type it, size_t n )
{
	std::advance(it, n);
	return it;
}

// returns the size of the LIterator
template<typename T>
size_t	LIterator<T>::size( void ) const
{
	return _size;
}

////// Operators
// Assigns the underlying iterator of another LIterator to this LIterator of equal size
template<typename T>
LIterator<T> &	LIterator<T>::operator=( LIterator const & other )
{
	if (this != &other && _size == other.size())
		_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the LIterator is pointing to
template<typename T>
typename LIterator<T>::reference	LIterator<T>::operator*( void ) const
{
	return *next(_it, _size - 1);
	// return *_it;
}

// Returns the address of the meaningful value that the LIterator is pointing to
template<typename T>
typename LIterator<T>::pointer		LIterator<T>::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the LIterator by index
template<typename T>
typename LIterator<T>::value_type	LIterator<T>::operator[]( size_t index )
{
	// LIterator	tmp(_it, 1);
	// tmp += (index * _size + _size - 1);
	// return *tmp.base();
	return value(index);
}

// Accesses the meaningful value from the LIterator by index, const version
template<typename T>
typename LIterator<T>::value_type	LIterator<T>::operator[]( size_t index ) const
{
	// LIterator	tmp(_it, 1);
	// tmp += (index * _size + _size - 1);
	// return *tmp.base();
	return value(index);
}

//// Increment and Decrement operators
// Advances the LIterator by _size
template<typename T>
LIterator<T> &	LIterator<T>::operator++( void )
{
	// for (size_t i = 0; i < _size; i++)
		// _it++;
	std::advance(_it, _size);
	return *this;
}

// Advances the LIterator by _size, post increment
template<typename T>
LIterator<T>	LIterator<T>::operator++( int )
{
	LIterator<T> tmp(*this);
	// for (size_t i = 0; i < _size; i++)
		// _it++;
	std::advance(_it, _size);
	return tmp;
}

// Decrements the LIterator by _size
template<typename T>
LIterator<T> &	LIterator<T>::operator--( void )
{
	// for (size_t i = 0; i < _size; i++)
		// _it--;
	std::advance(_it, -_size);
	return *this;
}

// Decrements the LIterator by _size, post decrement
template<typename T>
LIterator<T>	LIterator<T>::operator--( int )
{
	LIterator<T> tmp(*this);
	// for (size_t i = 0; i < _size; i++)
		// _it--;
	std::advance(_it, -_size);
	return tmp;
}

// Advances the LIterator by _size * increment
template<typename T>
LIterator<T> &	LIterator<T>::operator+=( difference_type increment )
{
	// for (size_t i = 0; i < _size; i++)
	// 	for (long j = 0; j < increment; j++)
	// 		_it++;
	std::advance(_it, _size * increment);
	return *this;
}

// Decrements the LIterator by _size * decrement
template<typename T>
LIterator<T> &	LIterator<T>::operator-=( difference_type decrement )
{
	// for (size_t i = 0; i < _size; i++)
	// 	for (long j = 0; j < decrement; j++)
	// 		_it--;
	std::advance(_it, -_size * decrement);
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two LIterators
template<typename T>
bool	LIterator<T>::operator==( LIterator const & rhs ) const
{
	return _it == rhs.base();
}

template<typename T>
bool	LIterator<T>::operator!=( LIterator const & rhs ) const
{
	return _it != rhs.base();
}

// template<typename T>
// bool	LIterator<T>::operator<( LIterator const & rhs ) const
// {
// 	return _it < rhs.base();
// }

// template<typename T>
// bool	LIterator<T>::operator<=( LIterator const & rhs ) const
// {
// 	return _it <= rhs.base();
// }

// template<typename T>
// bool	LIterator<T>::operator>( LIterator const & rhs ) const
// {
// 	return _it > rhs.base();
// }

// template<typename T>
// bool	LIterator<T>::operator>=( LIterator const & rhs ) const
// {
// 	return _it >= rhs.base();
// }

//// Arithmetic operators
// Returns an LIterator resulting from advancing the LIterator by increment
template<typename T>
LIterator<T>	LIterator<T>::operator+( difference_type increment )
{
	LIterator<T>	it(_it, _size);
	it += increment;
	return it;
}

// Returns the sum of the underlying iterators of two LIterators
template<typename T>
typename LIterator<T>::difference_type	LIterator<T>::operator+( LIterator const & rhs ) const
{
	// return (_it - rhs.base()) / _size;
	typename LIterator<T>::difference_type	dist = std::distance(rhs.base(), _it);
	return dist / _size;
}

// Returns an LIterator resulting from receding the LIterator by decrement
template<typename T>
LIterator<T>	LIterator<T>::operator-( typename LIterator<T>::difference_type decrement )
{
	LIterator	it(_it, _size);
	it -= decrement;
	return it;
}

// Returns the difference between the underlying iterators of two LIterators
template<typename T>
typename LIterator<T>::difference_type	LIterator<T>::operator-( LIterator const & rhs ) const
{
	// return (_it - rhs.base()) / _size;
	typename LIterator<T>::difference_type dist = std::distance(rhs.base(), _it);
	return dist / _size;
}

// For LIteratorUtils.cpp ??
// Swaps the contents of two LIterators
template<typename T>
void	swapLIterator( LIterator<T> lhs, LIterator<T> rhs )
{
	// size_t	size = lhs.size();
	// typename std::list<T>::iterator lhsIt = lhs.base();
	// typename std::list<T>::iterator rhsIt = rhs.base();
	// for (size_t i = 0; i < size; i++)
	// {
	// 	std::iter_swap(lhsIt, rhsIt);
	// 	lhsIt++;
	// 	rhsIt++;
	// }

	// We'll see if this works
	typename LIterator<T>::iterator_type lhsEnd = lhs.base();
	advance(lhsEnd, lhs.size());
	std::swap_ranges(lhs.base(), lhsEnd, rhs.base());
}

// For LIteratorUtils.cpp ??
// Removes lhs and inserts lhs at the position of rhs
template<typename T>
void	moveLIterator( LIterator<T> lhs, LIterator<T> rhs )
{
	size_t	size = lhs.size();
	typename std::list<T>::iterator lhsIt = lhs.base();
	typename std::list<T>::iterator rhsIt = rhs.base();
	for (size_t i = 0; i < size; i++)
	{
		std::iter_swap(lhsIt, rhsIt);
		lhsIt++;
		rhsIt++;
	}
}

template<typename T>
void	printLIterator( LIterator<T> start, LIterator<T> end )
{
	if (start.size() == 1)
	{
		for (LIterator<T> it = start; it != end; it++)
		{
			std::cout << it[0] << " ";
		}
		std::cout << std::endl;
		return ;
	}
	std::stringstream ss0;
	std::stringstream ss1;
	for (LIterator<T> it = start; it != end; it++)
	{
		typename LIterator<T>::iterator_type tmp = it.base();
		ss0 << " ";
		ss1 << "[";
		for (size_t k = 0; k < it.size(); k++)
		{
			for (unsigned int value = *tmp; value / 10 > 0; value /= 10)
				ss0 << " ";
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


#endif // LITERATOR_HPP
