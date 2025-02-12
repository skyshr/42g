#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<int>	_stack;

public:
	RPN();
	RPN( const RPN& src );
	RPN& operator=( const RPN& rhs );
	~RPN();

	class	DevisionByZeroException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. Devision by zero is not allowed!"; }
	};

	class	EmptyStackException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Error. There is no element left in the stack!"; }
	};

	void	doOperation( const std::string &arg );
	void	updateStack( const std::string &operation );
	void	insertStack( char c );
};

#endif