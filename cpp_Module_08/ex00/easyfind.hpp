#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
int	easyfind( T &container, int target )
{
	typename T::iterator it = std::find( container.begin(), container.end(), target );
	if ( it != container.end() )
		return std::distance( container.begin(), it );
	else
		return -1;
}
