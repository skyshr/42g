#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map< std::string, float > 	_btc;
	float							_val;

public:
	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange& src );
	BitcoinExchange& operator=( const BitcoinExchange& rhs );
	~BitcoinExchange();

	bool	makeBtcMap( const std::string& csv, char delimiter );
	void	getBitcoinExchange( const std::string& in, char delimiter );
	bool	checkDate( int year, int month, int day );
	bool	isValidDate( const std::string& date );
	bool	isValidBitcoinValue( const std::string& value );
	float	getTotalBitcoin( const std::string& date );

};

#endif