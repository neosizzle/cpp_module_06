#include <iostream>
#include <cmath> 
#include  "Converter.hpp"
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "param error\n";
		return 1;
	}
	Converter conv;
	conv.process_input(argv[1]);
	conv.printConversions(argv[1]);
	return 0;
}
