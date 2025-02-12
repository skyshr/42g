#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern instance created!" << std::endl;
}

Intern::Intern( const Intern &src )
{
	(void)src;
	std::cout << "Intern copy constructor called!" << std::endl;
}

Intern&		Intern::operator=( const Intern &rhs )
{
	std::cout << "Intern copy assignment operator called!" << std::endl;
	(void)rhs;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern instance deleted!" << std::endl;
}

AForm*	Intern::makeForm( const std::string &name, const std::string &target )
{
	int	i = 0;
	std::string	names[] ={ "shrubbery creation", "robotomy request", "presidential pardon" };
	while ( i < 3 && names[i].compare(name) )
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << names[i] << " form!" << std::endl;
		return new ShrubberyCreationForm( target );

	case 1:
		std::cout << "Intern creates " << names[i] << " form!" << std::endl;
		return new RobotomyRequestForm( target );

	case 2:
		std::cout << "Intern creates " << names[i] << " form!" << std::endl;
		return new PresidentialPardonForm( target );
	
	default:
		std::cout << "Intern cannot create " << name << " form!" << std::endl;
		throw NoFormExistException();
		break;
	}
	return 0;
}
