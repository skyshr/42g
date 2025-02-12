#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;

	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request1", "Bender");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}