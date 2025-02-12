#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_secret;
	int			_index;

	std::string _getInput( std::string str ) const;
	std::string	_printLen( std::string input ) const;

public:
	Contact();
	~Contact();

	void	init( void );
	void	setIndex( int index );
	void	view( int index ) const;
	void	display( int index ) const;
};

#endif