#ifndef VITERATORP_HPP
#define VITERATORP_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <vector>
#include <sstream>

class VIteratorP
{
public:

	typedef typename std::iterator_traits<std::vector<std::pair<unsigned int, unsigned int> >::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<std::vector<std::pair<unsigned int, unsigned int> >::iterator>::value_type		value_type;
	typedef typename std::iterator_traits<std::vector<std::pair<unsigned int, unsigned int> >::iterator>::difference_type	difference_type;
	typedef typename std::iterator_traits<std::vector<std::pair<unsigned int, unsigned int> >::iterator>::pointer			pointer;
	typedef typename std::iterator_traits<std::vector<std::pair<unsigned int, unsigned int> >::iterator>::reference			reference;
	typedef std::vector<std::pair<unsigned int, unsigned int> >::iterator													iterator_type;
	typedef std::vector<std::pair<unsigned int, unsigned int> >																container_type;

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

	VIteratorP &	operator=( VIteratorP const & other );

	// Member functions
	iterator_type	base( void ) const;
	iterator_type	end( void ) const;
	// difference_type	size( void ) const;
	size_t			size( void ) const;
	unsigned int	value( void ); // first
	unsigned int	index( void ); // second

	// Operators
	reference		operator*( void ) const;
	pointer			operator->( void ) const;
	value_type		operator[]( size_t index );
	value_type		operator[]( size_t index ) const;

	VIteratorP &		operator++( void );
	VIteratorP		operator++( int );
	VIteratorP &		operator--( void );
	VIteratorP		operator--( int );
	VIteratorP &		operator+=( difference_type increment );
	VIteratorP &		operator-=( difference_type decrement );

	bool			operator==( VIteratorP const & rhs ) const;
	bool			operator!=( VIteratorP const & rhs ) const;
	bool			operator<( VIteratorP const & rhs ) const;
	bool			operator<=( VIteratorP const & rhs ) const;
	bool			operator>( VIteratorP const & rhs ) const;
	bool			operator>=( VIteratorP const & rhs ) const;

	VIteratorP		operator+( difference_type increment );
	// difference_type	operator+( VIteratorP const & rhs ) const;
	VIteratorP		operator-( difference_type decrement );
	difference_type	operator-( VIteratorP const & rhs ) const;

};

// void	swapVIterator( VIteratorP lhs, VIteratorP rhs );
// void	printVIteratorP( VIteratorP start, VIteratorP end );
// void	printVIteratorP( VIteratorP & start, VIteratorP & end, int flag );

#endif // VITERATORP_HPP
