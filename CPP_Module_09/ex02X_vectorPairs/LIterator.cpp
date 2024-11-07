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
	return this->_it;
}

// returns the last iterator of this LIterator
LIterator::iterator_type	LIterator::end( void ) const
{
	return next(this->_it, this->_size);
}

// returns the value of the meaningul iterator in the LIterator
LIterator::value_type	LIterator::value( void )
{
	return *LIterator::next(this->_it, this->_size - 1);
}

// returns the value of the meaningul iterator in the LIterator past the given index
LIterator::value_type	LIterator::value( size_t index )
{
	return *LIterator::next(this->_it, index * this->_size + this->_size - 1);
}

// returns the value of the meaningul iterator in the LIterator past the given index
LIterator::value_type	LIterator::value( size_t index ) const
{
	return *LIterator::next(this->_it, index * this->_size + this->_size - 1);
}

// similar to std::next, but for LIterator, const version
LIterator::iterator_type	LIterator::next( iterator_type it, size_t n ) const
{
	std::advance(it, n);
	return it;
}

// similar to std::next, but for LIterator
LIterator::iterator_type	LIterator::next( iterator_type it, size_t n )
{
	std::advance(it, n);
	return it;
}

// returns the size of the LIterator
size_t	LIterator::size( void ) const
{
	return this->_size;
}

// swaps the contents of two LIterators
void	LIterator::swap( LIterator lhs, LIterator rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}

////// Operators
// Assigns the underlying iterator of another LIterator to this LIterator of equal size
LIterator &	LIterator::operator=( LIterator const & other )
{
	if (this != &other && this->_size == other.size())
		this->_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the LIterator is pointing to
LIterator::reference	LIterator::operator*( void ) const
{
	return *next(this->_it, this->_size - 1);
	// return *this->_it;
}

// Returns the address of the meaningful value that the LIterator is pointing to
LIterator::pointer		LIterator::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the LIterator by index
LIterator::value_type	LIterator::operator[]( size_t index )
{
	return value(index);
}

// Accesses the meaningful value from the LIterator by index, const version
LIterator::value_type	LIterator::operator[]( size_t index ) const
{
	return value(index);
}

//// Increment and Decrement operators
// Advances the LIterator by this->_size
LIterator &	LIterator::operator++( void )
{
	std::advance(this->_it, this->_size);
	return *this;
}

// Advances the LIterator by this->_size, post increment
LIterator	LIterator::operator++( int )
{
	LIterator tmp(*this);
	std::advance(this->_it, this->_size);
	return tmp;
}

// Decrements the LIterator by this->_size
LIterator &	LIterator::operator--( void )
{
	std::advance(this->_it, -this->_size);
	return *this;
}

// Decrements the LIterator by this->_size, post decrement
LIterator	LIterator::operator--( int )
{
	LIterator tmp(*this);
	std::advance(this->_it, -this->_size);
	return tmp;
}

// Advances the LIterator by this->_size * increment
LIterator &	LIterator::operator+=( difference_type increment )
{
	std::advance(this->_it, this->_size * increment);
	return *this;
}

// Decrements the LIterator by this->_size * decrement
LIterator &	LIterator::operator-=( difference_type decrement )
{
	std::advance(this->_it, -this->_size * decrement);
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two LIterators
bool	LIterator::operator==( LIterator const & rhs ) const
{
	return this->_it == rhs.base();
}

bool	LIterator::operator!=( LIterator const & rhs ) const
{
	return this->_it != rhs.base();
}

//// Arithmetic operators
// Returns an LIterator resulting from advancing the LIterator by increment
LIterator	LIterator::operator+( difference_type increment )
{
	LIterator it(this->_it, this->_size);
	it += increment;
	return it;
}

// Returns the sum of the underlying iterators of two LIterators
LIterator::difference_type	LIterator::operator+( LIterator const & rhs ) const
{
	// return (this->_it - rhs.base()) / this->_size;
	LIterator::difference_type dist = std::distance(rhs.base(), this->_it);
	return dist / this->_size;
}

// Returns an LIterator resulting from receding the LIterator by decrement
LIterator	LIterator::operator-( difference_type decrement )
{
	LIterator it(this->_it, this->_size);
	it -= decrement;
	return it;
}

// Returns the difference between the underlying iterators of two LIterators
LIterator::difference_type	LIterator::operator-( LIterator const & rhs ) const
{
	// return (this->_it - rhs.base()) / this->_size;
	LIterator::difference_type dist = std::distance(rhs.base(), this->_it);
	return dist / this->_size;
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
	std::ostringstream oss0;
	std::ostringstream oss1;
	for (LIterator it = start; it != end; it++)
	{
		LIterator::iterator_type tmp = it.base();
		oss0 << " ";
		oss1 << "[";
		for (size_t k = 0; k < it.size(); k++)
		{
			for (integer value = *tmp; value / 10 > 0; value /= 10)
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
