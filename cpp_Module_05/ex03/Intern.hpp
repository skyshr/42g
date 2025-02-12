#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
private:


public:

	Intern();
	Intern( const Intern &src );
	Intern& operator=( const Intern &rhs );
	~Intern();

	AForm*	makeForm( const std::string &name, const std::string &target );

	class	NoFormExistException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "There is no such form in the list!"; };
	};
};

#endif