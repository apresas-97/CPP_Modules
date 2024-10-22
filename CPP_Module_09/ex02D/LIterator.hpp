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

class LIterator
{
public:

	typedef typename std::iterator_traits<std::list<unsigned int>::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<std::list<unsigned int>::iterator>::value_type		value_type;
	typedef typename std::iterator_traits<std::list<unsigned int>::iterator>::difference_type	difference_type;
	typedef typename std::iterator_traits<std::list<unsigned int>::iterator>::pointer			pointer;
	typedef typename std::iterator_traits<std::list<unsigned int>::iterator>::reference			reference;
	typedef std::list<unsigned int>::iterator													iterator_type;
	typedef std::list<unsigned int>																container_type;

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
	// difference_type	operator+( LIterator const & rhs ) const;
	LIterator		operator-( difference_type decrement );
	difference_type	operator-( LIterator const & rhs ) const;

};

void	swapLIterator( LIterator lhs, LIterator rhs );
void	printLIterator( LIterator start, LIterator end );

#endif // LITERATOR_HPP
