#ifndef VITERATOR_HPP
#define VITERATOR_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <vector>

class VIterator
{
public:

	typedef typename std::iterator_traits<std::vector<int>::iterator>::iterator_category		iterator_category;
	typedef typename std::iterator_traits<std::vector<int>::iterator>::value_type				value_type;
	typedef typename std::iterator_traits<std::vector<int>::iterator>::difference_type			difference_type;
	typedef typename std::iterator_traits<std::vector<int>::iterator>::pointer					pointer;
	typedef typename std::iterator_traits<std::vector<int>::iterator>::reference				reference;
	typedef std::vector<int>::iterator															iterator_type;


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
void	makePairs( VIterator & lhs, VIterator & rhs );
void	printVIterator( VIterator & start, VIterator & end );













// template<typename Iterator>
// class PmergeIt
// {
// 	private:

// 		Iterator	_it;
// 		size_t		_size;

// 	public:

// 		typedef typename std::iterator_traits<Iterator>::iterator_category	iterator_category;
// 		typedef typename std::iterator_traits<Iterator>::value_type			value_type;
// 		typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
// 		typedef typename std::iterator_traits<Iterator>::pointer			pointer;
// 		typedef typename std::iterator_traits<Iterator>::reference			reference;
// 		typedef Iterator													iterator_type;

// 		PmergeIt( void );
// 		PmergeIt( Iterator it, size_t size );
// 		PmergeIt( PmergeIt<Iterator> it, size_t size );
// 		// PmergeIt( PmergeIt<Iterator> it, size_t size, int test );
// 		PmergeIt( PmergeIt const & other );
// 		~PmergeIt();
// 		PmergeIt &operator=( PmergeIt const &other );

// 		// Returns the real underlying iterator
// 		iterator_type	base( void ) const
// 		{
// 			return _it;
// 		}

// 		// Returns the size of the element the PmergeIt iterator is pointing to
// 		difference_type	size( void ) const
// 		{
// 			return _size;
// 		}

// 		// Returns the value that the PmergeIt iterator is pointing to
// 		reference	operator*( void ) const
// 		{
// 			return *(_it + _size - 1);
// 		}

// 		// Returns the address of the value that the PmergeIt iterator is pointing to
// 		pointer		operator->( void ) const
// 		{
// 			return &(operator*());
// 		}

// 		// Accesses the meaningful value from the PmergeIt iterator by index
// 		value_type	operator[]( size_t index )
// 		{
// 			return _it[index * _size + _size - 1];
// 		}

// 		value_type	operator[]( size_t index ) const
// 		{
// 			return _it[index * _size + _size - 1];
// 		}

// 		// Advances the PmergeIt iterator by _size
// 		PmergeIt &	operator++( void )
// 		{
// 			_it += _size;
// 			return *this;
// 		}

// 		PmergeIt	operator++( int )
// 		{
// 			PmergeIt tmp(*this);
// 			_it += _size;
// 			return tmp;
// 		}

// 		PmergeIt &	operator--( void )
// 		{
// 			_it -= _size;
// 			return *this;
// 		}

// 		PmergeIt	operator--( int )
// 		{
// 			PmergeIt tmp(*this);
// 			_it -= _size;
// 			return tmp;
// 		}

// 		PmergeIt &	operator+=( difference_type increment )
// 		{
// 			_it += _size * increment;
// 			return *this;
// 		}

// 		PmergeIt &	operator-=( difference_type decrement )
// 		{
// 			_it -= _size * decrement;
// 			return *this;
// 		}

// 		bool	operator==( PmergeIt const & rhs ) const
// 		{
// 			return _it == rhs.base();
// 		}

// 		bool	operator!=( PmergeIt const & rhs ) const
// 		{
// 			return _it != rhs.base();
// 		}

// 		bool	operator<( PmergeIt const & rhs ) const
// 		{
// 			return _it < rhs.base();
// 		}

// 		bool	operator<=( PmergeIt const & rhs ) const
// 		{
// 			return _it <= rhs.base();
// 		}

// 		bool	operator>( PmergeIt const & rhs ) const
// 		{
// 			return _it > rhs.base();
// 		}

// 		bool	operator>=( PmergeIt const & rhs ) const
// 		{
// 			return _it >= rhs.base();
// 		}

// 		PmergeIt	operator+( difference_type increment )
// 		{
// 			PmergeIt it(_it, _size);
// 			it += increment;
// 			return it;
// 		}

// 		PmergeIt	operator-( difference_type decrement )
// 		{
// 			PmergeIt it(_it, _size);
// 			it -= decrement;
// 			return it;
// 		}

// 		difference_type	operator-( PmergeIt const & rhs ) const
// 		{
// 			return (_it - rhs.base()) / _size;
// 		}

// 		difference_type operator+( PmergeIt const & rhs ) const
// 		{
// 			return (_it + rhs.base()) / _size;
// 		}

// 		// static void	swap( PmergeIt<Iterator> lhs, PmergeIt<Iterator> rhs )
// 		// {

// 		// }

// };

// template<typename Iterator>
// PmergeIt<Iterator>::PmergeIt( void )
// {
// 	// throw std::exception("PmergeIt must be initialised with an Iterator and an element size");
// 	throw std::exception(); // for now
// }

// // template<typename Iterator>
// // PmergeIt<Iterator>::PmergeIt( Iterator it, size_t size )
// // {
// // 	_it = it;
// // 	_size = it.size() * size;
// // }

// template<>
// PmergeIt<PmergeIt<std::vector<int>::iterator> >::PmergeIt( PmergeIt<std::vector<int>::iterator> it, size_t size )
// {
// 	_it = it;
// 	_size = size * it.size();
// }

// template<>
// PmergeIt<std::vector<int>::iterator>::PmergeIt( std::vector<int>::iterator it, size_t size ) : _it(it), _size(size)
// {

// }

// // template<typename Iterator>
// // PmergeIt<Iterator>::PmergeIt( PmergeIt<Iterator> it, size_t size, int test )
// // {
// // 	(void)test;
// // 	_it = it.base();
// // 	_size = size * it.size();
// // }

// template<typename Iterator>
// PmergeIt<Iterator>::PmergeIt( PmergeIt const &other )
// {
// 	*this = other;
// }

// template<typename Iterator>
// PmergeIt<Iterator>::~PmergeIt()
// {

// }

// template<typename Iterator>
// PmergeIt<Iterator> &	PmergeIt<Iterator>::operator=( PmergeIt const & other )
// {
// 	if (this != &other)
// 	{
// 		_it = other.base();
// 		_size = other.size();
// 	}
// 	return *this;
// }

// template<typename Iterator>
// void	swapPmergeIt( PmergeIt<Iterator> lhs, PmergeIt<Iterator> rhs )
// {
// 	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
// }

// template<typename Iterator>
// void	makePairs( PmergeIt<Iterator> & start, PmergeIt<Iterator> & end )
// {
// 	for (PmergeIt<Iterator> it = start; it != end; it += 2)
// 	{
// 		if (it[1] > it[0]) /// Make sure this is really correct
// 			swapPmergeIt(it, it + 1);
// 	}
// }

#endif // VITERATOR_HPP
