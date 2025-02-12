#ifndef	PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

	const std::string	_target;

public:
	PresidentialPardonForm( const std::string &target );
	PresidentialPardonForm( const PresidentialPardonForm &src );
	PresidentialPardonForm& operator=( const PresidentialPardonForm &rhs );
	~PresidentialPardonForm();

	std::string	getTarget() const;
	void		execute( Bureaucrat const & executor ) const;
};

#endif