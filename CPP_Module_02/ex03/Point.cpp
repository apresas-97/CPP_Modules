#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 )
{

}

Point::Point( const float x, const float y ) : _x( x ), _y( y )
{

}

Point::Point( Point const & src ) : _x(src.getX()), _y(src.getY())
{

}

Point::~Point()
{

}

Point &	Point::operator=( Point & rhs )
{
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
