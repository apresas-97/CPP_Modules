#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>

class Span
{
	public:
		Span( void );
		Span( const unsigned int size );
		Span( int *array, unsigned int size );
		Span( Span const & src );
		~Span();
		Span &	operator=( Span const & rhs );

		void			addMember( const int add );
		void			assign( int * begin, int * end );
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );
		void			randomFill( void );
		void			print( void ) const;

		int *			begin( void ) const;
		int *			end( void ) const;

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

	private:
		unsigned int		_size;
		unsigned int		_index;
		int *				_integers;

};


#endif // SPAN_HPP