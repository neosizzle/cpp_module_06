#include <iostream>
#include <cmath> 
#include  "Converter.hpp"
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./a.out [value]\n";
		return 1;
	}
	Converter conv;
	try
	{
		conv.process_input(argv[1]);
		conv.printConversions(argv[1]);
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	
	return 0;
}
