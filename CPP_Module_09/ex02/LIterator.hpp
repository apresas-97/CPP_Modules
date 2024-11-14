#ifndef LITERATOR_HPP
#define LITERATOR_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <list>
#include <sstream>

#include "PmergeMe_types.hpp"
#include "ansi.hpp"

class LIterator
{
public:

	typedef std::iterator_traits<list::iterator>::iterator_category	iterator_category;
	typedef std::iterator_traits<list::iterator>::value_type		value_type;
	typedef std::iterator_traits<list::iterator>::difference_type	difference_type;
	typedef std::iterator_traits<list::iterator>::pointer			pointer;
	typedef std::iterator_traits<list::iterator>::reference			reference;
	typedef list::iterator											iterator_type;
	typedef list													container_type;

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
	iterator_type	end( void ) const;
	size_t			size( void ) const;
	value_type		value( void );
	value_type		value( size_t index );
	value_type		value( size_t index ) const;
	iterator_type	next( iterator_type it, size_t n ) const;
	iterator_type	next( iterator_type it, size_t n );

	static void		swap( LIterator lhs, LIterator rhs );

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

typedef std::list<LIterator>				LIterator_list;
typedef std::list<LIterator_list::iterator>	LIterator_position_list;

void	printLIterator( LIterator start, LIterator end );

#endif // LITERATOR_HPP
