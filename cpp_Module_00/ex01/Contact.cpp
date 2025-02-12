#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput( std::string str ) const 
{
	std::string	input = "";
	bool		valid = false;

	while (!valid)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else 
		{
			std::cin.clear();
			std::cout << "Invalid input; please try again." << std::endl;
		}
	}
	return (input);
}

std::string Contact::_printLen( std::string input ) const
{
	if (input.length() > 10)
		return input.substr(0, 9) + ".";
	return input;
}

void	Contact::init( void ) 
{
	_firstName = _getInput("Enter your first name: ");
	_lastName = _getInput("Enter your last name: ");
	_nickname = _getInput("Enter your nickname: ");
	_phoneNumber = _getInput("Enter your phone number: ");
	_secret = _getInput("Enter your darkest secret: ");
	std::cout << std::endl;
}

void	Contact::setIndex( int index ) 
{
	_index = index;
}

void	Contact::view( int index ) const
{
	if (_firstName.empty() || _lastName.empty() || _nickname.empty() \
	|| _phoneNumber.empty() || _secret.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << _printLen(_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << _printLen(_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << _printLen(_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display( int index ) const
{
	if (_firstName.empty() || _lastName.empty() || _nickname.empty() \
	|| _phoneNumber.empty() || _secret.empty())
		return ;
	std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
	std::cout << std::endl;
	std::cout << "first name: " << _firstName << std::endl;
	std::cout << "last name: " << _lastName << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "phone number: " << _phoneNumber << std::endl;
	std::cout << "darkest secret: " << _secret << std::endl;
	std::cout << std::endl;
}
