#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
		{
			std::cerr << "You must introduce an anger level:" << std::endl;
			std::cerr << "Levels:\n\tDEBUG\n\tINFO\n\tWARNING\n\tERROR" << std::endl;
		}
		if (argc > 2)
			std::cerr << "Only one argument at a time!" << std::endl;
		return 1;
	}

	Harl		harl;
	harl.complain(argv[1]);

	return 0;
}
