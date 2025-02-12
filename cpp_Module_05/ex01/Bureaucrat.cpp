#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " is created!" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rhs )
{
	std::cout << "Bureaucrat copy assignment operator called!" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " is deleted!" << std::endl;
}

std::string	Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned( *this );
		std::cout << _name << " signed " << form.getName() << "!" << std::endl;
	}
	catch( Form::GradeTooLowException &e )
	{
		std::cout << _name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<< ( std::ostream& o, Bureaucrat &bau )
{
	o << bau.getName() << ", bureaucrat grade " << bau.getGrade()
	<< ".\n";
	return o;
}
