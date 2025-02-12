#include "Span.hpp"
#include <ctime>

#define	SIZE	10000

int	main()
{
	try
	{
		std::srand( std::time( 0 ) );
		Span sp = Span( SIZE );
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		for ( int i = 0; i < SIZE; i++ )
			sp.addNumber( std::rand() );

		Span sp1 = Span(sp);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
		// sp.addNumber(10);
	}
	catch( const std::exception& e )
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
