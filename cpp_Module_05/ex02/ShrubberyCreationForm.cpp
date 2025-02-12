#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target )
{
	std::cout << "ShrubberyCreationForm " << _target << " is created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm( src ), _target( src._target )
{
	std::cout << "ShrubberyCreationForm " << _target << " copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs )
{
	std::cout << "ShrubberyCreationForm " << _target << " copy assignment operator called!" << std::endl;
	if ( this != &rhs )
	{
		( std::string )this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _target << " is deleted!" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return _target;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if ( getIsSigned() == false )
		throw AForm::NotSignedException();
	if ( getGradeToExecute() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	
	std::string	file = _target + "_shrubbery";
	std::ofstream	fdout( file.c_str() );
	if (! fdout.is_open() )
	{
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	fdout << "^\n|";
	fdout.close();
}

