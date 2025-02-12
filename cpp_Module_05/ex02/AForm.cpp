#include "AForm.hpp"

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : 
			_name( name ), _isSigned( false ), _gradeToSign( gradeToSign ),
			_gradeToExecute( gradeToExecute )
{
	if ( gradeToSign < 1 || gradeToExecute < 1 )
		throw AForm::GradeTooHighException();
	else if ( gradeToSign > 150 || gradeToExecute > 150 )
		throw AForm::GradeTooLowException();

	std::cout << "AForm " << _name << " is created!" << std::endl;
}

AForm::AForm( const AForm &src ) : _name( src._name ), _isSigned( src._isSigned ),
							_gradeToSign( src._gradeToSign ), _gradeToExecute( src._gradeToExecute )
{
	std::cout << "AForm copy constructor called!" << std::endl;
}

AForm&	AForm::operator=( const AForm& rhs )
{
	std::cout << "AForm copy assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " is deleted!" << std::endl;
}

std::string	AForm::getName( void ) const
{
	return _name;
}

bool	AForm::getIsSigned( void ) const
{
	return _isSigned;
}

int		AForm::getGradeToSign( void ) const
{
	return _gradeToSign;
}

int		AForm::getGradeToExecute( void ) const
{
	return _gradeToExecute;
}

std::ostream&	operator<<( std::ostream &o, AForm& f )
{
	o << "Form name: " << f.getName() << std::endl
	<< "Form signed status: " << f.getIsSigned() << std::endl
	<< "Grade required to sign this form: " << f.getGradeToSign() << std::endl
	<< "Grade required to execute this form: " << f.getGradeToExecute() << std::endl;
	return o;
}

void	AForm::beSigned( Bureaucrat &bau )
{
	if ( bau.getGrade() > _gradeToSign )
		throw AForm::GradeTooLowException();
	_isSigned = true;
}