#include "PmergeMe.hpp"

void	parseArguments( int size, char **argv, integer *numbers )
{
	if (size < 1)
		throw std::exception();
	argv++;
	for (int i = 0; i < size; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> numbers[i];
		if (iss.fail() || !iss.eof())
			throw std::runtime_error("Invalid input received: " + std::string(argv[i]));
		else if (argv[i][0] == '-')
			throw std::runtime_error("Negative number received: " + std::string(argv[i]));
		else if (numbers[i] == 0)
			throw std::runtime_error("Zero received: " + std::string(argv[i]));
	}
}
