#include "Span.hpp"

Span::Span( void ) : _max(0), _integers(NULL), _i(0)
{

}

Span::Span( const unsigned int max ) : _max(max), _i(0)
{
	this->_integers = new int[max];
	for (unsigned int i = 0; i < max; i++)
		this->_integers[i] = int();
}

Span::Span( Span const & src ) : _max(0), _integers(NULL), _i(0)
{
	*this = src;
}

Span::~Span()
{
	delete [] this->_integers;
}

Span &	Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		// deep copy goes here
	}
	return *this;
}

void	Span::addMember( const int add )
{
	if (this->_i == this->_max)
		// throw exception
	this->_integers[this->_i] = add;
	this->_i++;
}

int	Span::shortestSpan( void ) const
{

}

int	Span::longestSpan( void ) const
{

}