#include "PmergeMe.hpp"

int	main( int ac, char **av )
{	
	PmergeMe	pm;

	if ( ac == 1 )
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		pm.init( ac, av );
		pm.pmergeVector();
		pm.pmergeList();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
