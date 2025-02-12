#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN( const RPN& src )
{
	*this = src;
}

RPN&	RPN::operator=( const RPN& rhs )
{
	( void )rhs;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::doOperation( const std::string &arg )
{
	std::istringstream iss( arg );
	std::string	content;

	while ( std::getline( iss, content, ' ' ) )
	{
		if ( content.length() != 1 )
		{
			std::cout << "Error" << std::endl;
			return ;
		}
		if ( !content.compare( "+" ) || !content.compare( "-" ) \
			|| !content.compare( "*" ) || !content.compare( "/" ) )
			updateStack( content );
		else if ( isdigit( content[0] ) )
			insertStack( content[0] );
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if ( _stack.size() != 1 )
		std::cout << "Error" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}

void	RPN::updateStack( const std::string &operation )
{
	int	first, second;
	if ( _stack.size() < 2 )
		throw EmptyStackException();
	second = _stack.top();
	_stack.pop();
	first = _stack.top();
	_stack.pop();

	if ( !operation.compare( "+" ) )
		_stack.push( first + second );
	else if ( !operation.compare( "-" ) )
		_stack.push( first - second );
	else if ( !operation.compare( "*" ) )
		_stack.push( first * second );
	else
	{
		if ( second == 0 )
			throw DevisionByZeroException();
		_stack.push( first / second );
	}
}

void	RPN::insertStack( char c )
{
	int	i = c - 48;
	_stack.push( i );
}
