#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& src );
	Bureaucrat& operator=( const Bureaucrat& rhs );
	~Bureaucrat();

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decrementGrade( void );

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Bureaucrat's grade is too high!"; }
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Bureaucrat's grade is too low!"; }
	};
};

std::ostream&	operator<< ( std::ostream& o, Bureaucrat &bau );

#endif