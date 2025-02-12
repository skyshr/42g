#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( target )
{
	std::cout << "PresidentialPardonForm " << _target << " is created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm( src ), _target( src._target )
{
	std::cout << "PresidentialPardonForm " << _target << " copy constructor called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs )
{
	std::cout << "PresidentialPardonForm " << _target << " copy assignment operator called!" << std::endl;
	if ( this != &rhs )
	{
		( std::string )this->_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << _target << " is deleted!" << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return _target;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if ( getIsSigned() == false )
		throw AForm::NotSignedException();
	if ( getGradeToExecute() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
