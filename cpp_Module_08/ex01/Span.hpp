#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

class Span
{
private:
	std::vector< int >	_vec;
	unsigned int		_index;
	unsigned int		_size;
	
public:
	Span( unsigned int n );
	Span( const Span& src );
	Span& operator=( const Span& rhs );
	~Span();

	void			addNumber( int n );
	unsigned int	shortestSpan( void );
	unsigned int	longestSpan( void );

	class	OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw() { 
				return "Unable to add a number because the container is full!"; 
			}
	};

	class	NoSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw() { 
				return "Unable to get span. Add more numbers!"; 
			}
	};
};

#endif