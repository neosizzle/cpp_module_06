#include "main.hpp"

uintptr_t serialize(Data* ptr)
{
	std::cout << "calling serialize...\n";
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	std::cout << "calling deserialize...\n";
	return reinterpret_cast<Data*>(raw);
}
int	main()
{
	Data data;
	data.str = "string from data\n";
	std::cout << "data from original " << data.str ;
	std::cout << "addr of original " << &data << "\n";
	uintptr_t serialized = serialize(&data);

	Data *newdata;
	newdata = deserialize(serialized);
	std::cout << "data from deserialized " << newdata->str ;
	std::cout << "addr of newdata " << newdata << "\n";

	return 0;
}
