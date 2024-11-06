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

void	VIteratorP::resize( size_t size )
{
	_size = size;
}

void	VIteratorP::swap( VIteratorP lhs, VIteratorP rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}

bool	VIteratorP::less( VIteratorP lhs, VIteratorP rhs )
{
	return (lhs->first < rhs->first);
}

bool	VIteratorP::greater( VIteratorP lhs, VIteratorP rhs )
{
	return (lhs->first > rhs->first);
}

// inserts the VIteratorP x into the vector v at the given position, and resets its index to 0
void	VIteratorP::insert( container_type & v, VIteratorP position, VIteratorP val )
{
	iterator_type	pos = position.base();
	iterator_type	it = val.base();
	while (it != val.end() - 1)
		v.insert(pos++, *it++);
	v.insert(pos, std::make_pair(it->first, 0));
}

// pushes the given VIteratorP x into the given vector v, and assigns index to its ->second
void	VIteratorP::push( container_type & v, VIteratorP x, unsigned int index )
{
	iterator_type	it = x.base();
	while (it != x.end() - 1)
		v.push_back(*it++);
	v.push_back(std::make_pair(it->first, index));
}

// Performs a binary search on the given range of VIteratorP and returns the first VIteratorP
// that has a ->first greater than the given value
VIteratorP	VIteratorP::upperBound( VIteratorP first, VIteratorP last, unsigned int val )
{
	VIteratorP	it = first;
	size_t		step;
	size_t		count = std::distance(first, last);
	while (count > 0)
	{
		it = first;
		step = count / 2;
		std::advance(it, step);
		// std::cout << "Y" << std::endl;
		if (!(val < it->first))
		{
			first = ++it;	
			count -= step + 1;
		}
		else
			count = step;
	}
	return first;
}

// Finds and returns the VIteratorP within the given range begin to end, that has as its ->second the given index
VIteratorP	VIteratorP::find( VIteratorP begin, VIteratorP end, unsigned int index )
{
	for (VIteratorP it = begin; it != end; ++it)
	{
		if (it->second == index)
			return it;
	}
	throw std::exception();
	return end;
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

VIteratorP &	VIteratorP::operator=( iterator_type it )
{
	_it = it;
	return *this;
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

void	swapVIteratorP( VIteratorP lhs, VIteratorP rhs )
{
	std::swap_ranges(lhs.base(), lhs.end(), rhs.base());
}


///

void	printVIteratorP( VIteratorP p )
{
	std::cout << BOLD << p->first << std::endl << DIM << p->second << RESET << std::endl;
}

void	printVIteratorP( std::ostringstream & oss0, std::ostringstream & oss1, VIteratorP p )
{
	oss0 << BOLD << p->first << RESET " ";
	oss1 << DIM << p->second << RESET " ";
}

void	printChain( VIteratorP start, VIteratorP end, std::string prefix )
{
	std::ostringstream oss0;
	std::ostringstream oss1;
	oss0 << prefix << ": ";
	oss1 << "i: ";
	for (VIteratorP it = start; it != end; it++)
	{
		printVIteratorP(oss0, oss1, it);
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
}

void	printChain( std::vector<std::pair<unsigned int, unsigned int> > & chain, std::string prefix )
{
	std::ostringstream oss0;
	std::ostringstream oss1;
	oss0 << prefix << ": ";
	oss1 << "i: ";
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = chain.begin(); it != chain.end(); it++)
	{
		oss0 << BOLD << it->first << RESET " ";
		oss1 << DIM << it->second << RESET " ";
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
}

void	printInsertion( std::vector<std::pair<unsigned int, unsigned int> > & v, VIteratorP position, VIteratorP element )
{
	std::cout << "Inserting: " BOLD << element->first << RESET " at position:" << std::endl;
	if (position == v.end())
	{
		std::cout << ITALIC "\tEND" RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << BOLD "\t" << position->first << RESET << std::endl;
		std::cout << DIM "\t" << position->second << RESET << std::endl;
	}
}

