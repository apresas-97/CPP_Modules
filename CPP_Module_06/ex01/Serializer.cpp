#include "Serializer.hpp"

Serializer::Serializer( void )
{
	// This class is not meant to be instanciated
}

Serializer::Serializer( Serializer const &other )
{
	// This class is not meant to be instanciated
	*this = other;
}

Serializer::~Serializer()
{
	// This class is not meant to be instanciated
}

Serializer &Serializer::operator=( Serializer const &other )
{
	// This class is not meant to be instanciated
	if ( this != &other )
	{

	}
	return *this;
}

uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data*>(raw);
}
