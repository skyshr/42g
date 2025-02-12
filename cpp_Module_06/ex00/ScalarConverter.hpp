#ifndef	SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>
#include <sstream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &src );
	ScalarConverter& operator=( const ScalarConverter &rhs );
	~ScalarConverter();

public:

	static void	convert( const std::string &str );
};

#endif
