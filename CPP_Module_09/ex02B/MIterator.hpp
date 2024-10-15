#ifndef MITERATOR_HPP
#define MITERATOR_HPP

#include <iterator>
#include <utility>

template<typename Iterator>
class MIterator
{
	public:

		typedef typename std::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename std::iterator_traits<Iterator>::value_type			value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer			pointer;
		typedef typename std::iterator_traits<Iterator>::reference			reference;
		typedef Iterator													iterator_type;

		MIterator( void ) : _it(), _size(0) {}
		MIterator( Iterator it, difference_type size ) : _it(it), _size(size) {}
		MIterator( MIterator const & src ) { *this = src; };
		~MIterator() {};
		MIterator &	operator=( MIterator const & rhs )
		{
			if (this != &rhs)
			{
				_it = rhs._it;
				_size = rhs._size;
			}
			return *this;
		}

		iterator_type	base( void ) const
		{
			return _it;
		}

		difference_type	size( void ) const
		{
			return _size;
		}

		reference	operator*( void ) const
		{
			Iterator	it = _it;
			std::advance(it, _size - 1);
			return *it;
		}

		pointer		operator->( void ) const
		{
			return &(operator*());
		}

		MIterator &	operator++( void )
		{
			std::advance(_it, _size);
			return *this;
		}

		MIterator &	operator--( void )
		{
			std::advance(_it, -_size);
			return *this;
		}

		MIterator &	operator+=(difference_type increment)
		{
			_it += _size * increment;
			return *this;
		}

		MIterator &	operator-=(difference_type decrement)
		{
			_it += _size * decrement;
			return *this;
		}

		bool	operator==( MIterator const & rhs )
		{
			return this->base() == rhs.base();
		}

		bool	operator!=( MIterator const & rhs )
		{
			return this->base() != rhs.base();
		}

		bool	operator<( MIterator const & rhs )
		{
			return this->base() < rhs.base();
		}

		bool	operator>( MIterator const & rhs )
		{
			return this->base() > rhs.base();
		}

		bool	operator<=( MIterator const & rhs )
		{
			return this->base() <= rhs.base();
		}

		bool	operator>=( MIterator const & rhs )
		{
			return this->base() >= rhs.base();
		}

		MIterator	operator+( difference_type size )
		{
			MIterator it(_it, _size);
			it += size;
			return it;
		}

		MIterator	operator-( difference_type size )
		{
			MIterator it(_it, _size);
			it -= size;
			return it;
		}

		difference_type	operator-( MIterator const & rhs )
		{
			return (this->base() - rhs.base()) / this->size();
		}

		void	iter_swap( MIterator & lhs, MIterator & rhs )
		{
			Iterator	lhs_end = lhs.base();
			std::advance(lhs_end, lhs.size());
	
			std::swap_ranges(lhs.base(), lhs_end, rhs.base());
		}

	private:

		Iterator		_it;
		difference_type	_size;
};

template<typename Iterator>
MIterator<Iterator>	makeMIterator( Iterator it, typename std::iterator_traits<Iterator>::difference_type size )
{
	return MIterator<Iterator>(it, size);
}

template<typename Iterator>
MIterator<Iterator>	makeMIterator( MIterator<Iterator> it, typename std::iterator_traits<Iterator>::difference_type size )
{
	size *= it.size();
	return MIterator<Iterator>(it.base(), size);
}

template<typename Iterator>
void	merge_insertion_sort( MIterator<Iterator> start, MIterator<Iterator> end )
{
	size_t	size = end - start;
	if (size < 2)
		return ;
	
	bool	has_stray = size % 2 != 0;

	MIterator<Iterator> end2 = has_stray ? std::prev(end) : end;
	

}

#endif // MITERATOR_HPP