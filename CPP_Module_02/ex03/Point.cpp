#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 )
{
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x( x ), _y( y )
{
	// std::cout << "Parametric Point constructor called" << std::endl;
}

Point::Point( Point const & src ) : _x(src.getX()), _y(src.getY())
{
	// std::cout << "Copy Point constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Point &	Point::operator=( Point & rhs )
{
	// std::cout << "Assignation Point operator called" << std::endl;
	// No assignments because _x and _y are const
	return rhs;
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}
