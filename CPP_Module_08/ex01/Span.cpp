#include "Span.hpp"

Span::Span( void ) : _size(0), _index(0), _integers(NULL)
{
	std::srand(std::time(NULL));
}

Span::Span( const unsigned int size ) : _size(size), _index(0)
{
	std::srand(std::time(NULL));
	this->_integers = new int[size];
	for (unsigned int i = 0; i < size; i++)
		this->_integers[i] = int();
}

Span::Span( int * array, unsigned int size ) : _size(size), _index(0)
{
	std::srand(std::time(NULL));
	this->_integers = new int[size];
	for (unsigned int i = 0; i < size; i++)
		this->addMember(array[i]);
}

Span::Span( Span const & src ) : _size(0), _index(0), _integers(NULL)
{
	*this = src;
}

Span::~Span()
{
	if (this->_integers != NULL)
		delete [] this->_integers;
}

Span &	Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		if (this->_integers != NULL)
			delete [] this->_integers;
		this->_size = rhs._size;
		this->_index = rhs._index;
		this->_integers = new int[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_integers[i] = rhs._integers[i];
	}
	return *this;
}

void	Span::addMember( const int add )
{
	if (this->_index == this->_size)
		throw Span::EmptySpanException();
	this->_integers[this->_index] = add;
	this->_index++;
}

void	Span::assign( int * begin, int * end )
{
	while (begin != end)
	{
		if (this->_index == this->_size)
			return ;
		this->addMember(*begin);
		begin++;
	}
}

void	Span::randomFill( void )
{
	for (unsigned int i = 0; i < this->_size; i++)
	{
		if (std::rand() % 2)
			this->addMember(std::rand());
		else
			this->addMember(-std::rand());
	}
}

unsigned int	Span::shortestSpan( void )
{
	if (this->_size < 2 || this->_index < 2 )
		throw Span::OnlyOneMemberException();
	if (this->_size == 0 || this->_index == 0)
		throw Span::EmptySpanException();
	std::sort(this->begin(), this->end());
	std::for_each(this->begin(), this->end(), [](int i) { std::cout << i << std::endl; });
}

unsigned int	Span::longestSpan( void )
{
	if (this->_size < 2 || this->_index < 2 )
		throw Span::OnlyOneMemberException();
	if (this->_size == 0 || this->_index == 0)
		throw Span::EmptySpanException();
	std::sort(this->begin(), this->end());
	int	largest_value = *(this->end() - 1);
	int	smallest_value = *(this->begin());
	return largest_value - smallest_value;
}

void	Span::print( void ) const
{
	std::sort(this->begin(), this->end());
	for (int * it = this->begin(); it != this->end(); it++)
		std::cout << *it << std::endl;
}

int *	Span::begin( void ) const
{
	return this->_integers;
}

int *	Span::end( void ) const
{
	return this->_integers + this->_index;
}

int	Span::getSize( void ) const
{
	return this->_size;
}

// Exceptions
const char*	Span::EmptySpanException::what() const throw()
{
	return "Span object is empty";
}

const char*	Span::OnlyOneMemberException::what() const throw()
{
	return "Span object has only one member";
}
