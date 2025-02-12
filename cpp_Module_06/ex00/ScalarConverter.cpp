#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( const ScalarConverter &src )
{
	(void)src;
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter &rhs )
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert( const std::string &str )
{
	if (!str.compare( "inf" ) || !str.compare( "inff" ) \
		|| !str.compare( "-inf" )  || !str.compare( "-inff" ) \
		|| !str.compare( "nan" ) || !str.compare( "nanf" ))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str[0] == 'i')
		{
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		else if (str[0] == '-')
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		return ;
	}

	int isChar, isInt, isFloat, isDouble;
	
	isChar = isInt = isFloat = isDouble = 0;
	if ( !isdigit( str[0] ) && str.length() == 1 )
		isChar = 1;
	else
	{
		int		idx = str.find( '.' );
		bool	intFlag = str.find( '.' ) == std::string::npos ? true : false;

		if ( !intFlag )
		{
			if ( !isdigit( str[idx + 1] ) )
				intFlag = true;
			int	_idx = 0;
			if ( str[_idx] == '+' || str[_idx] == '-' )
				_idx++;
			for ( int i = _idx; i < idx && !intFlag; i++ )	
			{
				if ( !isdigit( str[i] ) )
					intFlag = true;
			}	
		}
		if ( intFlag )
			isInt = 1;
		else
		{
			int	idx1 = str.find( 'f' );
			bool floatFlag = str.find( 'f' ) == std::string::npos ? false : true;
			
			if ( floatFlag )
			{
				for ( int i = idx + 1; i < idx1 && floatFlag; i++ )
				{
					if ( !isdigit( str[i] ))
						floatFlag = false;
				}
			}
			if ( floatFlag )
				isFloat = 1;
			else
				isDouble = 1;
		}

	}

	if ( isChar )
	{
		char	c = str[0];
		int		i = static_cast<int>( c );
		float	f = static_cast<float>( c );
		double 	d = static_cast<double>( c );

		if ( isprint( i ) )
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if ( isInt )
	{
		int		i = atoi( str.c_str() );
		char 	c = static_cast<char>( i );
		float 	f = static_cast<float>( i );
		double 	d = static_cast<double>( i );
			
		if ( i < 0 || i >= 128 )
			std::cout << "char: impossible" << std::endl;
		else if ( isprint( i ) )
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if ( isFloat )
	{
		float	f = strtof( str.c_str(), NULL );

		if ( f > static_cast<float>( INT_MAX ) \
				|| f < static_cast<float>( INT_MIN ))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>( f ) << ".0" << std::endl;
		}
		else
		{
			char 	c = static_cast<char>( f );
			int		i = static_cast<int>( f );
			double 	d = static_cast<double>( f );

			if ( i < 0 || i >= 128 )
				std::cout << "char: impossible" << std::endl;
			else if ( isprint( i ) )
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
	else
	{
		double	d = strtod( str.c_str(), NULL );

		if ( d > static_cast<double>( INT_MAX ) \
				|| d < static_cast<double>( INT_MIN ))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>( d ) << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
		else
		{
			char 	c = static_cast<char>( d );
			int		i = static_cast<int>( d );
			float	f = static_cast<float>( d );


			if ( i < 0 || i >= 128 )
				std::cout << "char: impossible" << std::endl;
			else if ( isprint( i ) )
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
}
