#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		// Bureaucrat	bau("bau", -1);
		Bureaucrat	bau1("bau1", 55);
		Bureaucrat	bau2("bau2", 1);
		Bureaucrat	bau3("bau3", 150);

		std::cout << std::endl;
		std::cout << "-----------Before-----------" << std::endl;

		// std::cout << bau;
		std::cout << bau1;
		std::cout << bau2;
		std::cout << bau3;

		bau1.incrementGrade();
		// bau2.incrementGrade();
		bau3.incrementGrade();
		std::cout << std::endl;
		// bau3.decrementGrade();
		// bau3.decrementGrade();

		std::cout << "-----------After-----------" << std::endl;

		std::cout << bau1;
		std::cout << bau2;
		std::cout << bau3;

		std::cout << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}