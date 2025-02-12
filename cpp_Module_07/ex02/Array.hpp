#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	T 				*_arr;
	unsigned int	_size;

public:
	Array( void );
	Array( unsigned int n );
	Array( const Array& src );
	Array& operator=( const Array& rhs );
	~Array();

	unsigned int	size( void ) const;

	T&	operator[]( unsigned int index );

	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Index is out of bounds!"; }
	};
};

#include "Array.tpp"