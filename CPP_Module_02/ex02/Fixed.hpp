#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

private:

	int	_value;
	static int const _fbits;

public:
	
	Fixed( void );
	Fixed( int const value );
	Fixed( float const value );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );

	bool	operator>( Fixed const & rhs );
	bool	operator<( Fixed const & rhs );
	bool	operator>=( Fixed const & rhs );
	bool	operator<=( Fixed const & rhs );
	bool	operator==( Fixed const & rhs );
	bool	operator!=( Fixed const & rhs );

	Fixed	operator+( Fixed const & rhs );
	Fixed	operator-( Fixed const & rhs );
	Fixed	operator*( Fixed const & rhs );
	Fixed	operator/( Fixed const & rhs );

	Fixed &	operator++( void );
	Fixed	operator++( int );
	Fixed &	operator--( void );
	Fixed	operator--( int );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	void	setValue( float const value );
	void	setValue( int const value );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed &			min( Fixed & f1, Fixed & f2 );
	static Fixed const &	min( Fixed const & f1, Fixed const & f2 );
	static Fixed &			max( Fixed & f1, Fixed & f2 );
	static Fixed const &	max( Fixed const & f1, Fixed const & f2 );

};

std::ostream & operator<<( std::ostream & out, const Fixed & rhs );

#endif
