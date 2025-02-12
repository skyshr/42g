#include "Serializer.hpp"

int	main()
{
	Data	data;

	data.id = 1;
	data.age = 30;
	data.wage = 6000.35;
	data.name = "ksuh";

	Data *n_data = Serializer::deserialize( Serializer::serialize( &data ) );

	std::cout << "id: " << n_data->id << std::endl;
	std::cout << "age: " << n_data->age << std::endl;
	std::cout << "wage: " << n_data->wage << std::endl;
	std::cout << "name: " << n_data->name << std::endl;
	
	return 0;
}
