#include "Base.hpp"

int	main()
{
	Base	*random;

	random = generate();
	identify( random );
	identify( *random );

	delete random;
	return 0;
}