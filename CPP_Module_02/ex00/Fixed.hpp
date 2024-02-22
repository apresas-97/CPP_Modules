#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

private:

	int	_value;
	static int const _fbits;

public:
	
	Fixed( void );
	Fixed( int value );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

#endif
