#include "BitcoinExchange.hpp"
#define	DATABASE	"data.csv"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange	btc;
	std::string	csv( DATABASE ), in( av[1] );

	if ( btc.makeBtcMap( csv, ',' ) == false )
		return 1;
	
	btc.getBitcoinExchange( in, '|' );
	return 0;
}
