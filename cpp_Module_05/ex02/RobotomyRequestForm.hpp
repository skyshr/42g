#ifndef	ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

	const std::string	_target;

public:
	RobotomyRequestForm( const std::string &target );
	RobotomyRequestForm( const RobotomyRequestForm &src );
	RobotomyRequestForm& operator=( const RobotomyRequestForm &rhs );
	~RobotomyRequestForm();

	std::string	getTarget() const;
	void		execute( Bureaucrat const & executor ) const;
};

#endif