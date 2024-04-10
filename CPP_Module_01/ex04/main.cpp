#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <target_line> <replacement_line>" << std::endl;
		return 1;
	}
	
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "An argument provided was empty" << std::endl;
		return 1;
	}

	std::ifstream	oldFile(filename.c_str());
	if (!oldFile.good())
	{
		std::cout << "File \"" << filename << "\" does not exists" << std::endl;
		return 1;
	}
	if (!oldFile.is_open())
	{
		std::cout << "Failed to open \"" << filename << "\"" << std::endl;
		return 1;
	}

	std::string		newFilename = filename + ".replace";
	std::ofstream	newFile(newFilename.c_str());
	if (!newFile.is_open())
	{
		std::cout << "Failed to create and open \"" << newFilename << "\"" << std::endl;
		oldFile.close();
		return 1;
	}

	bool changesMade = false;
	std::string line;
	while (std::getline(oldFile, line))
	{
		if (line == s1)
		{
			line = s2;
			changesMade = true;
		}
		if (!oldFile.eof())
			newFile << line << std::endl;
		else
			newFile << line;
	}
	if (changesMade == false)
	{
		std::remove(newFilename.c_str());
		std::cout << "File \"" << filename << "\" did not contain any matching line" << std::endl;
	}

	newFile.close();
	oldFile.close();
	return 0;
}
