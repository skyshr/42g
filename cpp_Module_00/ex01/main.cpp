#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.bad())
		{
			std::cout << "cin error" << std::endl;
			break ;
		}
		if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			phonebook.printContacts();
			phonebook.display();
		}
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Wrong option; please try again!" << std::endl;
	}
	return 0;
}
