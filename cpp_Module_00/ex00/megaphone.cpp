#include <iostream>

int	main( int argc, char **argv )
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	st = argv[i];
			for (int j = 0; j < (int)st.length(); j++)
				st[j] = toupper(st[j]);
			std::cout << st;
		}
		std::cout << std::endl;
	}
	return 0;
}
