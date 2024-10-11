#pragma once

#include <iostream>
#include <string>
#include <vector>

class Object
{
	public:
		~Object();
		Object( int value ) : _value(value) {};

		int	& operator[]( int index );

	private:
		int	_value;
};

int	&	Object::operator[]( int index )
{
	return _value;
}
