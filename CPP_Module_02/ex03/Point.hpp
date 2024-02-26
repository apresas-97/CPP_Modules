#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{

private:
	const Fixed _x;
	const Fixed _y;

public:
	Point( void );
	Point( float const x, float const y );
	Point( Point const & src );
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

	Point &	operator=( Point & rhs );

};

#endif