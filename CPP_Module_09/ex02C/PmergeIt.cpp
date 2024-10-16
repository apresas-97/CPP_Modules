#include "PmergeIt.hpp"

PmergeIt::PmergeIt( void )
{

}

PmergeIt::PmergeIt( PmergeIt const &other )
{
	*this = other;
}

PmergeIt::~PmergeIt()
{

}

PmergeIt &PmergeIt::operator=( PmergeIt const &other )
{
	if ( this != &other )
	{

	}
	return *this;
}
PmergeIt	PmergeIt::operator+( PmergeIt const & rhs )
{
	return ( *this + rhs );
}
PmergeIt	PmergeIt::operator-( PmergeIt const & rhs )
{
	return ( *this - rhs );
}
PmergeIt &	PmergeIt::operator++( void )
{
	return ( *this++ );
}
PmergeIt	PmergeIt::operator++( int )
{
	return ( *this++ );
}
PmergeIt &	PmergeIt::operator--( void )
{
	return ( *this-- );
}
PmergeIt	PmergeIt::operator--( int )
{
	return ( *this-- );
}
bool	PmergeIt::operator>( PmergeIt const & rhs ) const
{
	return ( *this > rhs );
}
bool	PmergeIt::operator>=( PmergeIt const & rhs ) const
{
	return ( *this >= rhs );
}
bool	PmergeIt::operator<( PmergeIt const & rhs ) const
{
	return ( *this < rhs );
}
bool	PmergeIt::operator<=( PmergeIt const & rhs ) const
{
	return ( *this <= rhs );
}
bool	PmergeIt::operator==( PmergeIt const & rhs ) const
{
	return ( *this == rhs );
}
bool	PmergeIt::operator!=( PmergeIt const & rhs ) const
{
	return ( *this != rhs );
}
