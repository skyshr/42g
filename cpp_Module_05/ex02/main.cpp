#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try {
		Bureaucrat bureaucrat( "ksuh", 11 );
		ShrubberyCreationForm form1( "Shrubbery" );
		RobotomyRequestForm form2( "Robotomy" );
		PresidentialPardonForm form3( "President" );

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		std::cout << std::endl;
		std::cout << form3;
		std::cout << std::endl;
		bureaucrat.signForm(form3);
		std::cout << std::endl;
		bureaucrat.executeForm(form3);
		std::cout << std::endl;
	} 
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}

	return 0;
}