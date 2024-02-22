#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
		{
			std::cerr << "You must introduce a level for Harl to say something" << std::endl;
			std::cerr << "Levels:\n\tdebug\n\tinfo\n\twarning\n\terror" << std::endl;
		}
		if (argc > 2)
			std::cerr << "Only one argument at a time!" << std::endl;
		return 0;
	}

	Harl		harl;
	std::string	level = argv[1];

	harl.complain(level);

	return 0;
}
