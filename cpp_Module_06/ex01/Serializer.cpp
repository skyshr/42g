#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer( const Serializer &src ){
	(void)src;
}

Serializer&	Serializer::operator=( const Serializer &rhs ){
	(void)rhs;
	return *this;
}

Serializer::~Serializer(){}

uintptr_t	Serializer::serialize( Data *data ) {
	return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*	Serializer::deserialize( uintptr_t raw ) {
	return ( reinterpret_cast< Data* >( raw ) );
}
