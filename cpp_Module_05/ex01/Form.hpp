#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:

	Form( std::string name, int gradeToSign, int gradeToExecute );
	Form( const Form &src );
	Form& operator=( const Form &rhs );
	~Form();

	class GradeTooHighException : public std::exception {
		public:
			virtual	const char* what() const throw() { return "Grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade is too low!"; }
	};

	std::string	getName( void ) const;
	bool		getIsSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;
	void		beSigned( Bureaucrat &bau );
};

std::ostream&	operator<<( std::ostream &o, Form& f );

#endif