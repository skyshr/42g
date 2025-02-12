#include "Span.hpp"

Span::Span( unsigned int n ) : _index( 0 ), _size( n )
{

}

Span::Span( const Span& src )
{
	*this = src;
}

Span&	Span::operator=( const Span& rhs )
{
	if ( this != &rhs )
	{
		this->_index = rhs._index;
		this->_size = rhs._size;
		this->_vec = rhs._vec;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber( int n )
{
	if (_index + 1 > _size)
		throw OutOfBoundsException();

	_vec.push_back( n );
	_index++;
}

unsigned int	Span::shortestSpan( void )
{
	if ( _index < 2 )
		throw NoSpanException();

	unsigned int shSpan = UINT_MAX;
	std::vector<int> vec(_size);
	vec.assign( _vec.begin(), _vec.end() );
	std::sort( vec.begin(), vec.end() );

	for ( unsigned int i = 1; i < _index ; i++ )
	{
		unsigned int diff = static_cast< unsigned int >( _vec[i] - _vec[i - 1] );
		if ( diff < shSpan )
			shSpan = diff;
	}
	return shSpan;
}

unsigned int	Span::longestSpan( void )
{
	if ( _index < 2 )
		throw NoSpanException();

	unsigned int minNumber = *std::min_element( _vec.begin(), _vec.end() );
	unsigned int maxNumber = *std::max_element( _vec.begin(), _vec.end() );

	return maxNumber - minNumber;
}
