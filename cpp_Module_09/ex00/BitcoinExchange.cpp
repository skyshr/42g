#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src )
{
	*this = src;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& rhs )
{
	if ( this != &rhs )
	{
		this->_btc.insert(rhs._btc.begin(), rhs._btc.end());
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool	BitcoinExchange::makeBtcMap( const std::string& csv, char delimiter )
{
	std::ifstream	csvIn( csv.c_str() );
	std::string 	content;

	if ( !csvIn.is_open() )
	{
		std::cout << "Error: could not open file." << std::endl;
		return false;
	}

	std::getline( csvIn, content );
	while ( std::getline( csvIn, content ) )
	{
		std::string key, value;
		std::istringstream iss( content );

		std::getline( iss, key, delimiter );
		if ( !std::getline( iss, value, delimiter ) )
			continue ;
		float btcValue = strtof( value.c_str(), NULL );
		_btc[key] = btcValue;
	}

	if ( _btc.empty() )
	{
		std::cout << "Error: no matching <key, value> pair in csv file!" << std::endl;
		csvIn.close();
		return false;
	}
	csvIn.close();
	return true;
}

void	BitcoinExchange::getBitcoinExchange( const std::string& in, char delimiter )
{
	std::ifstream 	fdIn( in.c_str() );
	std::string 	content;

	if ( !fdIn.is_open() )
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	std::getline( fdIn, content );
	while ( std::getline ( fdIn, content ) )
	{
		std::string date, amount;
		std::istringstream iss( content );

		std::getline( iss, date, delimiter );
		if ( !isValidDate( date ) )
			continue ;
		date.erase( date.length() - 1 , 1 );

		if ( !std::getline( iss, amount ) )
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if ( !isValidBitcoinValue( amount ) )
			continue ;

		float total = getTotalBitcoin( date );
		if ( total < 0.0f )
			std::cout << "Error: bad input => " << date << std::endl;
		else
			std::cout << date << " =>" << amount << " = " << total << std::endl;
	}
	fdIn.close();
}

bool	BitcoinExchange::isValidDate( const std::string& date )
{
	std::istringstream 	iss( date );
	std::string 		yy, mm, dd;
	int					y, m, d;
	bool				flag;

	if ( !std::getline( iss, yy, '-' ) \
		|| !std::getline( iss, mm, '-' ) \
		|| !std::getline( iss, dd, '-' ) )
		flag = false;
	else
	{
		y = atoi( yy.c_str() ), m = atoi( mm.c_str() ), d = atoi( dd.c_str() );
		flag = checkDate( y, m, d );
	}

	if ( !flag )
		std::cout << "Error: bad input => " << date << std::endl;
	return flag;
}

bool	BitcoinExchange::checkDate( int year, int month, int day )
{
	if ( year < 2009 || year > 2023 || month < 0 || month > 12 )
		return false;

	if ( month % 2 == 1 )
	{
		if ( month <= 7 )
			return ( day > 0 && day <= 31 );
		else
			return ( day > 0 && day <= 30 );
	}
	else
	{
		if ( month <= 6 )
		{
			if ( month == 2 )
			{
				if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) )
					return ( day > 0 && day <= 29 );
				else
					return ( day > 0 && day <= 28 );
			}
			else
				return ( day > 0 && day <= 30 );
		}
		else
			return ( day > 0 && day <= 31 );
	}
}

bool	BitcoinExchange::isValidBitcoinValue( const std::string& amount )
{
	float btcFloat = strtof( amount.c_str(), NULL );
	if ( btcFloat < 0.0f )
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if ( btcFloat > 1000.0f )
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	_val = btcFloat;
	return true;
}

float	BitcoinExchange::getTotalBitcoin( const std::string& date )
{
	if ( _btc.find( date ) != _btc.end() )
			return _btc[date] * _val;
	else
	{
		std::map<std::string, float>::iterator it;

		for ( it = _btc.begin(); it!= _btc.end(); it++ )
		{
			if ( it->first > date )
				break ;
		}
		if ( it == _btc.begin() )
			return -1.0f;
		it--;
		return it->second * _val;
	}
}
