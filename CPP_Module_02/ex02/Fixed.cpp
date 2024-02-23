#include "Fixed.hpp"

// Non member variables:

int const Fixed::_fbits = 8;

// Constructors:

Fixed::Fixed( void ) : _value( 0 )
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( int const value )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fbits;
}

Fixed::Fixed( float const value )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fbits));
}

// Operator overloads:

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs )
		this->_value = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>( Fixed const & rhs )
{
	return this->_value > rhs._value;
}

bool	Fixed::operator<( Fixed const & rhs )
{
	return this->_value < rhs._value;
}

bool	Fixed::operator>=( Fixed const & rhs )
{
	return this->_value >= rhs._value;
}

bool	Fixed::operator<=( Fixed const & rhs )
{
	return this->_value <= rhs._value;
}

bool	Fixed::operator==( Fixed const & rhs )
{
	return this->_value == rhs._value;
}

bool	Fixed::operator!=( Fixed const & rhs )
{
	return this->_value != rhs._value;
}

Fixed	Fixed::operator+( Fixed const & rhs )
{
	Fixed result;
	result.setRawBits( this->getRawBits() + rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator-( Fixed const & rhs )
{
	Fixed result;
	result.setRawBits( this->getRawBits() - rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator*( Fixed const & rhs )
{
	Fixed result;
	result._value = (this->_value * rhs._value) >> Fixed::_fbits;
	return result;
}

Fixed	Fixed::operator/( Fixed const & rhs )
{
	Fixed result;
	result._value = (this->_value << Fixed::_fbits) / rhs._value;
	return result;
}

Fixed &	Fixed::operator++( void )
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);
	++this->_value;
	return tmp;
}

Fixed &	Fixed::operator--( void )
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);
	--this->_value;
	return tmp;
}

// Member functions:

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
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

// Non member functions

Fixed &	Fixed::min( Fixed & f1, Fixed & f2 )
{
	return (f1.getRawBits() < f2.getRawBits()) ? f1 : f2;
}

Fixed const &	Fixed::min( Fixed const & f1, Fixed const & f2 )
{
	return (f1.getRawBits() < f2.getRawBits()) ? f1 : f2;
}

Fixed &	Fixed::max( Fixed & f1, Fixed & f2 )
{
	return (f1.getRawBits() > f2.getRawBits()) ? f1 : f2;
}

Fixed const &	Fixed::max( Fixed const & f1, Fixed const & f2 )
{
	return (f1.getRawBits() > f2.getRawBits()) ? f1 : f2;
}

// << overload

std::ostream & operator<<( std::ostream & out, const Fixed & rhs )
{
	out << rhs.toFloat();
	return out;
}
