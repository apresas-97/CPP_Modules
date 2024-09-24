#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>

class Span
{
	public:
		Span( void );
		Span( const unsigned int max );
		Span( Span const & src );
		~Span();
		Span &	operator=( Span const & rhs );

		void	addMember( const int add );
		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;
	
	class EmptySpanException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	private:
		const unsigned int	_max;
		unsigned int		_i;
		int *				_integers;


};

#endif // SPAN_HPP