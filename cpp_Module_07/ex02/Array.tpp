#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _size( 0 ), _arr( new T() )
{
}

template <typename T>
Array<T>::Array( unsigned int n ) : _size( n )
{ 
	_arr = new T[n]();
}

template <typename T>
Array<T>::Array( const Array& src ) : _size( src._size )
{ 
	_arr = new T[_size]();
	for ( unsigned int i = 0; i < _size; i++ )
		_arr[i] = src._arr[i];
	_arr[0]++;
}

template <typename T>
Array<T>&	Array<T>::operator=( const Array& rhs ) 
{ 
	if ( this != &rhs )
	{
		delete[] _arr;
		this->_size = rhs._size;
		this->_arr = new T[_size]();
		for ( unsigned int i = 0; i < _size; i++ )
			this->_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() 
{
	delete[] _arr;
}

template <typename T>
unsigned int	Array<T>::size( void ) const
{ 
	return _size; 
}

template <typename T>
T&	Array<T>::operator[]( unsigned int index )
{
	if ( index >= _size)
		throw Array<T>::OutOfBoundsException();
	return _arr[index];
}
