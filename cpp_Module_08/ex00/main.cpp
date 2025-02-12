#include "easyfind.hpp"

int main()
{
	int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::vector< int >	vec( arr, arr + sizeof( arr ) / sizeof( int ) );
	std::list< int >	list( arr, arr + sizeof( arr ) / sizeof( int ) );

	int idx1 = easyfind(vec, 5);
	int idx2 = easyfind(list, 5);
	std::cout << "vector easyfind index of element 5: " << idx1 << std::endl;
	std::cout << "list easyfind index of element 5: " << idx1 << std::endl;

	idx1 = easyfind(vec, 11);
	idx2 = easyfind(list, 11);
	std::cout << "vector easyfind index of element 11: " << idx2 << std::endl;
	std::cout << "list easyfind index of element 11: " << idx2 << std::endl;

	return 0;
}
