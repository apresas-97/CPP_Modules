#ifndef VITERATORP_HPP
#define VITERATORP_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <vector>
#include <sstream>

#include "PmergeMe_types.hpp"
#include "ansi.hpp"

class VIteratorP
{
public:

	typedef typename std::iterator_traits<pair_vector::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<pair_vector::iterator>::value_type		value_type;
	typedef typename std::iterator_traits<pair_vector::iterator>::difference_type	difference_type;
	typedef typename std::iterator_traits<pair_vector::iterator>::pointer			pointer;
	typedef typename std::iterator_traits<pair_vector::iterator>::reference			reference;
	typedef pair_vector::iterator													iterator_type;
	typedef pair_vector																container_type;

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
	integer				value( void ); // first
	integer				index( void ); // second
	void				resize( size_t size );

	static void			swap( VIteratorP lhs, VIteratorP rhs );
	static bool			less( VIteratorP lhs, VIteratorP rhs );
	static bool			greater( VIteratorP lhs, VIteratorP rhs );
	static VIteratorP	find( VIteratorP begin, VIteratorP end, integer index );
	static void			insert( container_type & v, VIteratorP position, VIteratorP val );
	static void			push( container_type & v, VIteratorP x, integer index );
	static VIteratorP	upperBound( VIteratorP first, VIteratorP last, integer val );

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
	VIteratorP			operator-( difference_type decrement );
	difference_type		operator-( VIteratorP const & rhs ) const;

};

void	printVIteratorP( VIteratorP p );
void	printVIteratorP( std::ostringstream & oss0, std::ostringstream & oss1, VIteratorP p );
void	printChain( VIteratorP start, VIteratorP end, std::string prefix );
void	printChain( pair_vector & chain, std::string prefix );
void	printInsertion( pair_vector & v, VIteratorP position, VIteratorP element );

#endif // VITERATORP_HPP
