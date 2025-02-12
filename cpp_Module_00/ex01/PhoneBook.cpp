#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_idx = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact( void ) 
{
	int	idx;

	idx = _idx % 8;
	_contacts[idx].init();
	_contacts[idx].setIndex(idx);
	_idx++;
}

void	PhoneBook::printContacts( void ) const
{
	if (_idx == 0)
	{
		std::cout << "Nothing to display" << std::endl;
		return ;
	}
	std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << std::flush;
	std::cout << "|" << std::setw(10) << "FIRST NAME" << std::flush;
	std::cout << "|" << std::setw(10) << "LAST NAME" << std::flush;
	std::cout << "|" << std::setw(10) << "NICKNAME" << std::flush;
	std::cout << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		_contacts[i].view(i);
	std::cout << std::endl;
}

void	PhoneBook::display( void ) const
{
	int	index;
	int	idx;

	if (_idx == 0)
		return ;
	idx = (_idx >= 8) ? 7 : _idx - 1;
	std::cout << "Enter index to display ( 0 ~ " << idx << " ): " << std::flush;
	std::cin >> index;
	if (std::cin.good() && index >= 0 && \
		((_idx >= 8 && index < 8) || (_idx < 8 && index < _idx)))
		_contacts[index].display(index);
	else 
		std::cout << "Invalid input" << std::endl;
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << std::endl;
}
