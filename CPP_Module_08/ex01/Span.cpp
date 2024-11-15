#include "Span.hpp"

Span::Span( void ) : _size(0), _index(0), _integers(NULL)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span( const unsigned int size ) : _size(size), _index(0)
{
	std::cout << "Span constructor called" << std::endl;
	this->_integers = new int[size];
	for (unsigned int i = 0; i < size; i++)
		this->_integers[i] = int();
}

Span::Span( Span const & src ) : _size(0), _index(0), _integers(NULL)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
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

void	Span::addNumber( const int add )
{
	if (this->_index == this->_size)
		throw Span::AddOutOfBoundsException();
	this->_integers[this->_index] = add;
	this->_index++;
}

unsigned int	Span::shortestSpan( void ) const
{
	if (this->_size == 0 || this->_index == 0)
		throw Span::EmptySpanException();
	if (this->_size < 2 || this->_index < 2 )
		throw Span::OnlyOneMemberException();
	
	std::vector<int>	sorted_vec(this->begin(), this->end());
	std::sort(sorted_vec.begin(), sorted_vec.end());
	std::vector<int>	diff(sorted_vec.size());
	std::adjacent_difference(sorted_vec.begin(), sorted_vec.end(), diff.begin());

	return *std::min_element(diff.begin() + 1, diff.end());
}

unsigned int	Span::longestSpan( void ) const
{
	if (this->_size == 0 || this->_index == 0)
		throw Span::EmptySpanException();
	if (this->_size < 2 || this->_index < 2 )
		throw Span::OnlyOneMemberException();

	std::vector<int>	sorted_vec(this->begin(), this->end());
	std::sort(sorted_vec.begin(), sorted_vec.end());
	int	largest_value = *(sorted_vec.end() - 1);
	int	smallest_value = *(sorted_vec.begin());
	return largest_value - smallest_value;
}

void	Span::print( void ) const
{
	std::cout << "Span contents:" << std::endl;
	for (int * it = this->begin(); it != this->end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
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

const char*	Span::AddOutOfBoundsException::what() const throw()
{
	return "Attempted to add more members than the Span size allows";
}
