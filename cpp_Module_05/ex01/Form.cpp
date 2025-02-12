#include "Form.hpp"

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : 
			_name( name ), _isSigned( false ), _gradeToSign( gradeToSign ),
			_gradeToExecute( gradeToExecute )
{
	if ( gradeToSign < 1 || gradeToExecute < 1 )
		throw Form::GradeTooHighException();
	else if ( gradeToSign > 150 || gradeToExecute > 150 )
		throw Form::GradeTooLowException();

	std::cout << "Form " << _name << " is created!" << std::endl;
}

Form::Form( const Form &src ) : _name( src._name ), _isSigned( src._isSigned ),
							_gradeToSign( src._gradeToSign ), _gradeToExecute( src._gradeToExecute )
{
	std::cout << "Form copy constructor called!" << std::endl;
}

Form&	Form::operator=( const Form& rhs )
{
	std::cout << "Form copy assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " is deleted!" << std::endl;
}

std::string	Form::getName( void ) const
{
	return _name;
}

bool	Form::getIsSigned( void ) const
{
	return _isSigned;
}

int		Form::getGradeToSign( void ) const
{
	return _gradeToSign;
}

int		Form::getGradeToExecute( void ) const
{
	return _gradeToExecute;
}

std::ostream&	operator<<( std::ostream &o, Form& f )
{
	o << "Form name: " << f.getName() << std::endl
	<< "Form signed status: " << f.getIsSigned() << std::endl
	<< "Grade required to sign this form: " << f.getGradeToSign() << std::endl
	<< "Grade required to execute this form: " << f.getGradeToExecute() << std::endl;
	return o;
}

void	Form::beSigned( Bureaucrat &bau )
{
	if ( bau.getGrade() > _gradeToSign )
		throw Form::GradeTooLowException();
	_isSigned = true;
}