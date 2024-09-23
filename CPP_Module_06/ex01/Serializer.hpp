#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h> // c++98 compatible, unlike cstdint

#include "Data.hpp"

class Serializer
{
	private:
		Serializer( void );
		Serializer( Serializer const &other );
		~Serializer();
		Serializer &operator=( Serializer const &other );

	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
};

#endif // SERIALIZER_HPP
