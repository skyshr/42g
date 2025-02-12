#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0)
{
}

PmergeMe::PmergeMe( const PmergeMe& src )
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=( const PmergeMe& rhs )
{
	( void )rhs;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::init( int ac, char **av )
{
	float	fMin = 1.0;
	float	fMax = static_cast<float>( std::numeric_limits<int>::max() );

	for ( int i = 1; i < ac; i++ )
	{
		float f = strtof( av[i], NULL );
		if ( f < fMin || f > fMax )
			throw OutofBoundsException();
		int n = static_cast<int>( f );
		if ( std::find( _originVector.begin(), _originVector.end(), n ) != _originVector.end() )
			throw DuplicationException();
		_originVector.push_back( n );
		_originList.push_back( n );
	}
	_originSorted = _originVector;
	std::sort( _originSorted.begin(), _originSorted.end() );
	_size = ac - 1;
	initJacobsthal();
	std::cout << "Before: " << _originVector << std::endl;
	std::cout << "After:  " << _originSorted << std::endl;
}

void	PmergeMe::initJacobsthal( void )
{
	int	prev = 1, next = 1;
	int	temp;

	while ( 2 * next <= _size )
	{
		_jacobsthal.push_back( next - 1 );
		temp = prev;
		prev = next;
		next += 2 * temp;
	}
	_jacobsthal.push_back( next - 1 );
}

void	PmergeMe::pmergeVector( void )
{
	time_t	timeStart, timeEnd;

	timeStart = clock();
	_vec = mergeInsertSortVector( _originVector );
	checkVector();
	timeEnd = clock();
	printTime( timeStart, timeEnd, "vector" );
}

std::vector<int>	PmergeMe::mergeInsertSortVector( std::vector<int> &main )
{
	int	size = main.size();
	if ( size <= 1 )
		return main;

	std::multimap<int, int> m;
	std::vector<int> _main( size / 2 ), _side( size / 2 + size % 2 );
	std::vector<int>::iterator it = main.begin();
	int temp = 0;
	if ( size % 2 )
	{
		temp = main.back();
		main.pop_back();
	}
	int	idx = 0;
	for ( ; it != main.end(); it+=2 )
	{
		if ( *it > *( it + 1 ) )
		{
			m.insert( std::pair<int, int> ( *it, *( it + 1 ) ) );
			_main[idx++] = *it;
		}
		else
		{
			m.insert( std::pair<int, int> ( *( it + 1 ), *it ) );
			_main[idx++] = *( it + 1 );
		}
	}
	_main = mergeInsertSortVector( _main );
	idx = 0;
	for ( it = _main.begin(); it != _main.end(); it++ )
		_side[idx++] = m.find( *it )->second;
	if ( temp )
		_side[idx] = temp;
	insertSortVector( _main, _side );
	return _main;
}

void	PmergeMe::insertSortVector( std::vector<int> &main, std::vector<int> &side )
{
	int	index = 1;
	int	size = side.size();
	int	startIdx = _jacobsthal[index];

	main.insert( main.begin(), side[0] );
	while ( _jacobsthal[index - 1] + 1 < size )
	{
		startIdx = _jacobsthal[index] >= size ? size - 1 : _jacobsthal[index];
		int	high = startIdx + _jacobsthal[index - 1] + 1;
		while ( startIdx > _jacobsthal[index - 1] )
		{
			int insertIndex = binarySearchVector( main, 0, high, side[startIdx] );
			main.insert( main.begin() + insertIndex, side[startIdx] );
			startIdx--;
			if ( insertIndex == high )
				high--;
		}
		index++;
	}
}

int		PmergeMe::binarySearchVector( std::vector<int> &main, int low, int high, int value )
{
	while ( low < high )
	{
		int mid = ( low + high ) / 2;
		if ( main[mid] >= value )
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

void	PmergeMe::checkVector( void )
{
	if ( _vec.size() != static_cast<unsigned int>( _size ) )
		throw VectorSizeNotMatchException();

	int index = 0;
	for ( ; index < _size; index++ )
	{
		if ( _vec[index] != _originSorted[index] )
			throw VectorValueNotMatchException();
	}
}

void	PmergeMe::pmergeList( void )
{
	time_t	timeStart, timeEnd;

	timeStart = clock();
	_lst = mergeInsertSortList( _originList );
	checkList();
	timeEnd = clock();
	printTime( timeStart, timeEnd, "list  " );
}

std::list<int>	PmergeMe::mergeInsertSortList( std::list<int> &main )
{
	int	size = main.size();
	if ( size <= 1 )
		return main;

	std::multimap<int, int> m;
	std::list<int> _main, _side;
	std::list<int>::iterator it = main.begin();
	std::list<int>::iterator it1 = main.begin();
	it1++;
	int temp = 0;
	if ( size % 2 )
	{
		temp = main.back();
		main.pop_back();
	}

	while ( it != main.end() )
	{
		if ( *it > *it1 )
		{
			m.insert( std::pair<int, int> ( *it, *it1 ) );
			_main.push_back( *it );
		}
		else
		{
			m.insert( std::pair<int, int> ( *it1, *it ) );
			_main.push_back( *it1 );
		}
		it++;
		it++;
		it1++;
		it1++;
	}

	_main = mergeInsertSortList( _main );
	for ( it = _main.begin(); it != _main.end(); it++ )
		_side.push_back( m.find( *it )->second );
	if ( temp )
		_side.push_back( temp );
	insertSortList( _main, _side );
	return _main;
}

void	PmergeMe::insertSortList( std::list<int> &main, std::list<int> &side )
{
	int	index = 1;
	int	size = side.size();
	int	startIdx = _jacobsthal[index];
	std::list<int>::iterator	itrLeft;
	std::list<int>::iterator	itrRight;

	main.insert( main.begin(), side.front() );
	while ( _jacobsthal[index - 1] + 1 < size )
	{
		startIdx = _jacobsthal[index] >= size ? size - 1 : _jacobsthal[index];
		int	high = startIdx + _jacobsthal[index - 1] + 1;
		itrRight = side.begin();
		for ( int i = 0; i < startIdx; i++ )
			itrRight++;
		while ( startIdx > _jacobsthal[index - 1] )
		{
			std::list<int>::iterator itr = binarySearchList( main, 0, high, *itrRight );
			main.insert( itr, *itrRight );
			startIdx--;
			itrRight--;
		}
		index++;
	}
}

std::list<int>::iterator	PmergeMe::binarySearchList( std::list<int> &main, int low, int high, int value )
{
	std::list<int>::iterator itrSave, itr;
	itrSave = main.begin();
	while ( low < high )
	{
		int mid = ( low + high ) / 2;
		int count = mid - low;
		itr = itrSave;
		for ( int i = 0; i < count; i++ )
			itr++;
		if ( *itr >= value )
			high = mid;
		else
		{
			low = mid + 1;
			itrSave = ++itr;
		}
	}
	return itrSave;
}

void	PmergeMe::checkList( void )
{
	if ( _lst.size() != static_cast<unsigned int>( _size ) )
		throw ListSizeNotMatchException();

	int index = 0;
	std::list<int>::iterator itr = _lst.begin();
	for ( ; itr != _lst.end(); itr++ )
	{
		if ( *itr != _originSorted[index++] )
			throw ListValueNotMatchException();
	}
}

void	PmergeMe::printTime( time_t start, time_t end, const std::string &msg )
{
	double	result;
	
	result = static_cast<double> ( end - start ) / 1000;
	std::cout << std::fixed;
	std::cout.precision( 5 );
	std::cout << "Time to process a range of   " << _size 
	<< " elements with std::" << msg << ":  " << result << " us" << std::endl;
	std::cout.unsetf( std::ios::fixed );
}

std::ostream&	operator<<( std::ostream& o, std::vector<int>& vec )
{
	std::vector<int>::iterator itr;

	for ( itr = vec.begin(); itr != vec.end(); itr++ )
	{
		o << *itr << " ";		
	}
	return o;
}

std::ostream&	operator<<( std::ostream& o, std::list<int>& lst )
{
	std::list<int>::iterator itr;

	for ( itr = lst.begin(); itr != lst.end(); itr++ )
	{
		o << *itr << " ";		
	}
	return o;
}