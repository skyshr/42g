#include "iter.hpp"

int	main()
{
	int	arr[5] = { 0, 1, 2, 3, 4 };
	iter( arr, 5, squared<const int> );
	iter( arr, 5, printData<int> );

	float arr1[3] = { 0.1, 0.2, 0.3 };
	iter( arr1, 3, squared<int> );
	iter( arr1, 3, printData<int> );

	return 0;
}