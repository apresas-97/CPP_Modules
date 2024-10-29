#ifndef VITERATOR_HPP
#define VITERATOR_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <vector>
#include <sstream>

#define BLOCKS 3
#define VISUALIZER 2
#define TRUE_VECTOR 1
#define DEFAULT 0

class VIterator
{
public:

	typedef typename std::iterator_traits<std::vector<unsigned int>::iterator>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<std::vector<unsigned int>::iterator>::value_type			value_type;
	typedef typename std::iterator_traits<std::vector<unsigned int>::iterator>::difference_type		difference_type;
	typedef typename std::iterator_traits<std::vector<unsigned int>::iterator>::pointer				pointer;
	typedef typename std::iterator_traits<std::vector<unsigned int>::iterator>::reference			reference;
	typedef std::vector<unsigned int>::iterator														iterator_type;
	typedef std::vector<unsigned int>																container_type;

private:

	iterator_type	_it;
	size_t			_size;
	
	VIterator( void );

public:

	VIterator( iterator_type it, size_t size );
	VIterator( iterator_type it );
	VIterator( VIterator it, size_t size );
	VIterator( VIterator const & other );
	~VIterator();

	VIterator &	operator=( VIterator const & other );

	// Member functions
	iterator_type	base( void ) const;
	// difference_type	size( void ) const;
	size_t			size( void ) const;

	// Operators
	reference		operator*( void ) const;
	pointer			operator->( void ) const;
	value_type		operator[]( size_t index );
	value_type		operator[]( size_t index ) const;

	VIterator &		operator++( void );
	VIterator		operator++( int );
	VIterator &		operator--( void );
	VIterator		operator--( int );
	VIterator &		operator+=( difference_type increment );
	VIterator &		operator-=( difference_type decrement );

	bool			operator==( VIterator const & rhs ) const;
	bool			operator!=( VIterator const & rhs ) const;
	bool			operator<( VIterator const & rhs ) const;
	bool			operator<=( VIterator const & rhs ) const;
	bool			operator>( VIterator const & rhs ) const;
	bool			operator>=( VIterator const & rhs ) const;

	VIterator		operator+( difference_type increment );
	// difference_type	operator+( VIterator const & rhs ) const;
	VIterator		operator-( difference_type decrement );
	difference_type	operator-( VIterator const & rhs ) const;

};

void	swapVIterator( VIterator lhs, VIterator rhs );
void	printVIterator( VIterator & start, VIterator & end );
void	printVIterator( VIterator & start, VIterator & end, int flag );

#endif // VITERATOR_HPP
