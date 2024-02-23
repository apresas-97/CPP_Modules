#include "Fixed.hpp"

int const Fixed::_fbits = 8;

Fixed::Fixed( void ) : _value( 0 )
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
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( int const value )
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fbits;
}

Fixed::Fixed( float const value )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fbits));
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs )
		this->_value = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

void	Fixed::setValue( float const value )
{
	this->_value = value * (1 << Fixed::_fbits);
}

void	Fixed::setValue( int const value )
{
	this->_value = value << Fixed::_fbits;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_value) / (1 << Fixed::_fbits);
}

int	Fixed::toInt( void ) const
{
	return roundf(static_cast<float>(this->_value) / (1 << Fixed::_fbits));
}

std::ostream & operator<<( std::ostream & out, const Fixed & rhs )
{
	out << rhs.toFloat();
	return out;
}
