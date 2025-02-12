#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void )
{
	srand( time(NULL) );
	int	nbr = rand() % 3;
	if ( nbr == 0 )
		return new A();
	else if ( nbr == 1 )
		return new B();
	else
		return new C();
}

void	identify( Base *p )
{
	std::cout << "Identify function by pointer called!" << std::endl;

	if ( A *a = dynamic_cast< A* >( p ) )
	{
		std::cout << "Base type is A!" << std::endl;
	}
	else if ( B *b = dynamic_cast< B* >( p ) )
	{
		std::cout << "Base type is B!" << std::endl;
	}
	else
	{
		std::cout << "Base type is C!" << std::endl;
	}
}

void	identify( Base &p )
{
	std::cout << "Identify function by reference called!" << std::endl;

	try
	{
		A& a = dynamic_cast< A& >( p );
		std::cout << "input type is A" << std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{}
	
	try
	{
		B& b = dynamic_cast< B& >( p );
		std::cout << "input type is B" << std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{}

	try
	{
		C& c = dynamic_cast< C& >( p );
		std::cout << "input type is C" << std::endl;
		(void)c;
		return;
	}
	catch(const std::exception& e)
	{}
}