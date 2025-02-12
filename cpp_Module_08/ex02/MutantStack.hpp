#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <list>

template <typename T>

class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack() {}
	MutantStack( const MutantStack& src ) { *this = src; }
	MutantStack& operator=( const MutantStack& rhs )
	{
		if ( this != &rhs )
		{
			std::stack<T>::operator=( rhs );
		}
		return *this;
	}
	~MutantStack() {};

	typedef typename std::deque<T>::iterator	iterator;

	iterator	begin( void )
	{
		return this->c.begin();
	}

	iterator	end( void )
	{
		return this->c.end();
	}
};

#endif