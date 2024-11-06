#ifndef VITERATORP_HPP
#define VITERATORP_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <vector>
#include <sstream>
#include "ansi.hpp"

typedef std::pair<unsigned int, unsigned int>	pair_t;

class VIteratorP
{
public:

	typedef typename std::iterator_traits<std::vector<pair_t>::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<std::vector<pair_t>::iterator>::value_type		value_type;
	typedef typename std::iterator_traits<std::vector<pair_t>::iterator>::difference_type	difference_type;
	typedef typename std::iterator_traits<std::vector<pair_t>::iterator>::pointer			pointer;
	typedef typename std::iterator_traits<std::vector<pair_t>::iterator>::reference			reference;
	typedef std::vector<pair_t>::iterator													iterator_type;
	typedef std::vector<pair_t>																container_type;

private:

	iterator_type	_it;
	size_t			_size;
	
	VIteratorP( void );

public:

	VIteratorP( iterator_type it, size_t size );
	VIteratorP( iterator_type it );
	VIteratorP( VIteratorP it, size_t size );
	VIteratorP( VIteratorP const & other );
	~VIteratorP();


	// Member functions
	iterator_type		base( void ) const;
	iterator_type		end( void ) const;
	size_t				size( void ) const;
	unsigned int		value( void ); // first
	unsigned int		index( void ); // second
	void				resize( size_t size );

	static void			swap( VIteratorP lhs, VIteratorP rhs );
	static bool			less( VIteratorP lhs, VIteratorP rhs );
	static bool			greater( VIteratorP lhs, VIteratorP rhs );
	static VIteratorP	find( VIteratorP begin, VIteratorP end, unsigned int index );
	static void			insert( container_type & v, VIteratorP position, VIteratorP val );
	static void			push( container_type & v, VIteratorP x, unsigned int index );
	static VIteratorP	upperBound( VIteratorP first, VIteratorP last, unsigned int val );

	// Operators
	VIteratorP &		operator=( VIteratorP const & other );

	reference			operator*( void ) const;
	pointer				operator->( void ) const;
	value_type			operator[]( size_t index );
	value_type			operator[]( size_t index ) const;

	VIteratorP &		operator=( iterator_type it );
	VIteratorP &		operator++( void );
	VIteratorP			operator++( int );
	VIteratorP &		operator--( void );
	VIteratorP			operator--( int );
	VIteratorP &		operator+=( difference_type increment );
	VIteratorP &		operator-=( difference_type decrement );

	bool				operator==( VIteratorP const & rhs ) const;
	bool				operator!=( VIteratorP const & rhs ) const;
	bool				operator<( VIteratorP const & rhs ) const;
	bool				operator<=( VIteratorP const & rhs ) const;
	bool				operator>( VIteratorP const & rhs ) const;
	bool				operator>=( VIteratorP const & rhs ) const;

	VIteratorP			operator+( difference_type increment );
	// difference_type	operator+( VIteratorP const & rhs ) const;
	VIteratorP			operator-( difference_type decrement );
	difference_type		operator-( VIteratorP const & rhs ) const;

};

void	swapVIteratorP( VIteratorP lhs, VIteratorP rhs );

// void	swapVIterator( VIteratorP lhs, VIteratorP rhs );
// void	printVIteratorP( VIteratorP start, VIteratorP end );
// void	printVIteratorP( VIteratorP & start, VIteratorP & end, int flag );

#endif // VITERATORP_HPP
