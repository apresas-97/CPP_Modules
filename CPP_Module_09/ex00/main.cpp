#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string filename = argv[1];

	BitcoinExchange *exchange;
	try
	{
		exchange = new BitcoinExchange();
	}
	catch( const std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}

	exchange->checkConversion(filename);

	delete exchange;
	return 0;
}