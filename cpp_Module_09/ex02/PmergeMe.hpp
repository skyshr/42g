#ifndef	PmergeMe_HPP
#define	PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

class PmergeMe
{
private:
	std::vector<int>	_originVector;
	std::vector<int>	_originSorted;
	std::list<int>		_originList;
	std::vector<int>	_vec;
	std::list<int>		_lst;
	std::vector<int>	_jacobsthal;
	int					_size;

	void	initJacobsthal( void );
	void	printTime( time_t start, time_t end, const std::string &msg );

	std::vector<int>	mergeInsertSortVector( std::vector<int> &main );
	void				insertSortVector( std::vector<int> &main, std::vector<int> &side );
	int					binarySearchVector( std::vector<int> &main, int low, int high, int value );
	void				checkVector( void );

	std::list<int>					mergeInsertSortList( std::list<int> &main );
	void							insertSortList( std::list<int> &main, std::list<int> &side );
	std::list<int>::iterator		binarySearchList( std::list<int> &main, int low, int high, int value );
	void							checkList( void );

public:
	PmergeMe();
	PmergeMe( const PmergeMe& src );
	PmergeMe& operator=( const PmergeMe& rhs );
	~PmergeMe();

	void	init( int ac, char **av );
	void	pmergeVector( void );
	void	pmergeList( void );
	
	class	OutofBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Only positive numbers are allowed!"; }
	};

	class	DuplicationException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Duplicates found!"; }
	};

	class	VectorSizeNotMatchException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Final vector does not match the origin's size!"; }
	};

	class	VectorValueNotMatchException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Final vector does not match the origin's value!"; }
	};

	class	ListSizeNotMatchException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Final list does not match the origin's size!"; }
	};

	class	ListValueNotMatchException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Final list does not match the origin's value!"; }
	};
};

std::ostream&	operator<<( std::ostream& o, std::vector<int>& vec );
std::ostream&	operator<<( std::ostream& o, std::list<int>& vec );

#endif