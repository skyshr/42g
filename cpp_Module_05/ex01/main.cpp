#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat bureaucrat( "ksuh", 11 );
		Form form( "form1", 10, 15 );

		std::cout << std::endl;
		bureaucrat.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl;
	} 
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}