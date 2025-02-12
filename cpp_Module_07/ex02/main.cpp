#include "Array.hpp"

int	main()
{
	Array<int>		arr( void );
	Array<double>	arr1( 3 );
	Array<int>		arr2( 5 );
	Array<int>		arr3( arr2 );
	Array<int>		arr4( 3 );

	for ( unsigned int i = 0; i < arr1.size(); i++ )
		arr1[i] = i * i;
	arr4 = arr2;

	std::cout << "---------------arr1-----------------" << std::endl;
	for ( unsigned int i = 0; i < arr1.size(); i++ )
		std::cout << "arr1[" << i << "]: " << arr1[i] << ", " << std::flush;
	std::cout << std::endl;
	std::cout << std::endl;
	arr1[0] = 10;

	std::cout << "---------------arr1-----------------" << std::endl;
	for ( unsigned int i = 0; i < arr1.size(); i++ )
		std::cout << "arr1[" << i << "]: " << arr1[i] << ", " << std::flush;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------------arr2-----------------" << std::endl;
	for ( unsigned int i = 0; i < arr2.size(); i++ )
		std::cout << "arr2[" << i << "]: " << arr2[i] << ", " << std::flush;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------------arr3-----------------" << std::endl;
	for ( unsigned int i = 0; i < arr3.size(); i++ )
		std::cout << "arr3[" << i << "]: " << arr3[i] << ", " << std::flush;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---------------arr4-----------------" << std::endl;
	for ( unsigned int i = 0; i < arr4.size(); i++ )
		std::cout << "arr4[" << i << "]: " << arr4[i] << ", " << std::flush;
	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Valid index( arr1[2] ): " << arr1[2] << std::endl;
		std::cout << "Invalid index( arr1[3] ): " << arr1[3] << std::endl;
	} catch ( std::exception& e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
