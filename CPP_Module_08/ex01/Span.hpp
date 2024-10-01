#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <climits>
#include <iostream>
#include <vector>
#include <numeric>

class Span
{
	public:
		Span( void );
		Span( const unsigned int size );
		Span( Span const & src );
		~Span();
		Span &	operator=( Span const & rhs );

		void			addNumber( const int add );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		template<typename T>
		void			addRange( T begin, T end );

		int *			begin( void ) const;
		int *			end( void ) const;

		void			print( void ) const;
		int				getSize( void ) const;
	
	class EmptySpanException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class OnlyOneMemberException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class AddOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	private:
		unsigned int		_size;
		unsigned int		_index;
		int *				_integers;

};

template<typename T>
void	Span::addRange( T begin, T end )
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

#endif // SPAN_HPP