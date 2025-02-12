#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:

	AForm( std::string name, int gradeToSign, int gradeToExecute );
	AForm( const AForm &src );
	AForm& operator=( const AForm &rhs );
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
		public:
			virtual	const char* what() const throw() { return "Grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade is too low!"; }
	};

	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Form is not yet signed!"; }
	};

	std::string		getName( void ) const;
	bool			getIsSigned( void ) const;
	int				getGradeToSign( void ) const;
	int				getGradeToExecute( void ) const;
	void			beSigned( Bureaucrat &bau );
	virtual void	execute( Bureaucrat const & executor ) const = 0;
};

std::ostream&	operator<<( std::ostream &o, AForm& f );

#endif