#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int value ) : _value( value )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{

}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs )
		this->_value = rhs.getRawBits();
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
