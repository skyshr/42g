#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( target )
{
	std::cout << "RobotomyRequestForm " << _target << " is created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm( src ), _target( src._target )
{
	std::cout << "RobotomyRequestForm " << _target << " copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs )
{
	std::cout << "RobotomyRequestForm " << _target << " copy assignment operator called!" << std::endl;
	if ( this != &rhs )
	{
		( std::string )this->_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << " is deleted!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return _target;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if ( getIsSigned() == false )
		throw AForm::NotSignedException();
	if ( getGradeToExecute() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	
	std::cout << "DRRRRRRRRRRRRRRRRR" << std::endl;
	static int	i;
	if ( i % 2 == 0 )
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed!" << std::endl;
	i++;
}
