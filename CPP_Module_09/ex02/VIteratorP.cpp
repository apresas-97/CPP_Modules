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
	return this->_it;
}

VIteratorP::iterator_type	VIteratorP::end( void ) const
{
	return this->_it + this->_size;
}

// returns the size of the VIteratorP
// VIteratorP::difference_type	VIteratorP::size( void ) const
size_t	VIteratorP::size( void ) const
{
	return this->_size;
}

integer	VIteratorP::value( void )
{
	return this->_it[this->_size - 1].first;
}

integer	VIteratorP::index( void )
{
	return this->_it[this->_size - 1].second;
}

void	VIteratorP::resize( size_t size )
{
	this->_size = size;
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
void	VIteratorP::push( container_type & v, VIteratorP x, integer index )
{
	iterator_type	it = x.base();
	while (it != x.end() - 1)
		v.push_back(*it++);
	v.push_back(std::make_pair(it->first, index));
}

// Performs a binary search on the given range of VIteratorP and returns the first VIteratorP that has a ->first greater than the given value
VIteratorP	VIteratorP::upperBound( VIteratorP first, VIteratorP last, integer val )
{
	VIteratorP		it = first;
	difference_type	step;
	difference_type	count = std::distance(first, last);
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
VIteratorP	VIteratorP::find( VIteratorP begin, VIteratorP end, integer index )
{
	for (VIteratorP it = begin; it != end; ++it)
	{
		if (it->second == index)
			return it;
	}
	return end;
}

////// Operators
// Assigns the underlying iterator of another VIteratorP to this VIteratorP of equal size
VIteratorP &	VIteratorP::operator=( VIteratorP const & other )
{
	if (this != &other && this->_size == other.size())
		this->_it = other.base();
	return *this;
}

//// Dereference operators
// Returns the meaningful value that the VIteratorP is pointing to
VIteratorP::reference	VIteratorP::operator*( void ) const
{
	return this->_it[this->_size - 1];
}

// Returns the address of the meaningful value that the VIteratorP is pointing to
VIteratorP::pointer		VIteratorP::operator->( void ) const
{
	return &(operator*());
}

// Accesses the meaningful value from the VIteratorP by index
VIteratorP::value_type	VIteratorP::operator[]( size_t index )
{
	return this->_it[index * this->_size + this->_size - 1];
}

// Accesses the meaningful value from the VIteratorP by index, const version
VIteratorP::value_type	VIteratorP::operator[]( size_t index ) const
{
	return this->_it[index * this->_size + this->_size - 1];
}

VIteratorP &	VIteratorP::operator=( iterator_type it )
{
	this->_it = it;
	return *this;
}

//// Increment and Decrement operators
// Advances the VIteratorP by this->_size
VIteratorP &	VIteratorP::operator++( void )
{
	this->_it += this->_size;
	return *this;
}

// Advances the VIteratorP by this->_size, post increment
VIteratorP	VIteratorP::operator++( int )
{
	VIteratorP tmp(*this);
	this->_it += this->_size;
	return tmp;
}

// Decrements the VIteratorP by this->_size
VIteratorP &	VIteratorP::operator--( void )
{
	this->_it -= this->_size;
	return *this;
}

// Decrements the VIteratorP by this->_size, post decrement
VIteratorP	VIteratorP::operator--( int )
{
	VIteratorP tmp(*this);
	this->_it -= this->_size;
	return tmp;
}

// Advances the VIteratorP by this->_size * increment
VIteratorP &	VIteratorP::operator+=( difference_type increment )
{
	this->_it += increment * this->_size;
	return *this;
}

// Decrements the VIteratorP by this->_size * decrement
VIteratorP &	VIteratorP::operator-=( difference_type decrement )
{
	this->_it -= decrement * this->_size;
	return *this;
}

//// Comparison operators
// Compares the underlying iterator of two VIteratorPs
bool	VIteratorP::operator==( VIteratorP const & rhs ) const
{
	return this->_it == rhs.base();
}

bool	VIteratorP::operator!=( VIteratorP const & rhs ) const
{
	return this->_it != rhs.base();
}

bool	VIteratorP::operator<( VIteratorP const & rhs ) const
{
	return this->_it < rhs.base();
}

bool	VIteratorP::operator<=( VIteratorP const & rhs ) const
{
	return this->_it <= rhs.base();
}

bool	VIteratorP::operator>( VIteratorP const & rhs ) const
{
	return this->_it > rhs.base();
}

bool	VIteratorP::operator>=( VIteratorP const & rhs ) const
{
	return this->_it >= rhs.base();
}

//// Arithmetic operators
// Advances the VIteratorP by increment * this->_size
VIteratorP	VIteratorP::operator+( difference_type increment )
{
	VIteratorP it(this->_it, this->_size);
	it += increment;
	return it;
}

// Decrements the VIteratorP by decrement * this->_size
VIteratorP	VIteratorP::operator-( difference_type decrement )
{
	VIteratorP it(this->_it, this->_size);
	it -= decrement;
	return it;
}

// Returns the difference between the underlying iterators of two VIteratorPs
VIteratorP::difference_type	VIteratorP::operator-( VIteratorP const & rhs ) const
{
	return (this->_it - rhs.base()) / this->_size;
}

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

void	printChain( pair_vector & chain, std::string prefix )
{
	std::ostringstream oss0;
	std::ostringstream oss1;
	oss0 << prefix << ": ";
	oss1 << "i: ";
	for (pair_vector::iterator it = chain.begin(); it != chain.end(); it++)
	{
		oss0 << BOLD << it->first << RESET " ";
		oss1 << DIM << it->second << RESET " ";
	}
	std::cout << oss0.str() << std::endl;
	std::cout << oss1.str() << std::endl;
}

void	printInsertion( pair_vector & v, VIteratorP position, VIteratorP element )
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

