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

	std::string fileString;
	oldFile.seekg(0, std::ios::end);
	fileString.resize(oldFile.tellg());
	oldFile.seekg(0, std::ios::beg);
	oldFile.read(&fileString[0], fileString.size());
	oldFile.close();

	bool 	changesMade = false;
	size_t	pos = fileString.find(s1); 
	while (pos != std::string::npos)
	{
		fileString.erase(pos, s1.length());
		fileString.insert(pos, s2);
		changesMade = true;
		pos = fileString.find(s1, pos + s2.length());
	}
	if (fileString[fileString.length() - 1] != '\n')
		newFile << fileString << std::endl;
	else
		newFile << fileString;

	if (changesMade == false)
	{
		std::remove(newFilename.c_str());
		std::cout << "File \"" << filename << "\" did not contain any matches" << std::endl;
	}

	newFile.close();
	oldFile.close();
	return 0;
}
