#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>

std::string	findAndReplace(std::string &str, const std::string &s1, const std::string &s2, bool &changesMade);
std::string	storeFile(const std::string filepath);
int			checkFile(std::ifstream &file, const std::string filepath);
int			checkFile(std::ofstream &file, const std::string filepath);

int	main(int argc, char **argv)
{
	// Check for correct number of arguments
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <target_line> <replacement_line>" << std::endl;
		return 1;
	}

	// Initialise string variables for the arguments
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// Check if any of the arguments are empty
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "An argument provided was empty" << std::endl;
		return 1;
	}
	// Check if the target and replacement strings are the same
	if (s1 == s2)
	{
		std::cout << "The target and replacement strings are the same" << std::endl;
		return 1;
	}

	// Store the file in a string using the storeFile function
	std::string fileString = storeFile(filename);
	// storeFile returns an empty string on error, so we check for that
	if (fileString.empty())
		return 1;

	std::string		newFilename = filename + ".replace";
	// If the file we want to create already exists, we remove it,
	// Because this subject says to copy the contents of <filename> into a NEW file.
	if (access(newFilename.c_str(), F_OK) == 0)
		std::remove(newFilename.c_str());

	// Create the new file with the appropriate name
	std::ofstream	newFile(newFilename);
	// Check if the new file was created and opened successfully
	if (!newFile.is_open())
	{
		std::cout << "Failed to create and open \"" << newFilename << "\"" << std::endl;
		return 1;
	}

	// Create a flag to check if any changes were made
	bool	changesMade = false;
	// Call the findAndReplace function to replace all occurrences of s1 with s2
	fileString = findAndReplace(fileString, s1, s2, changesMade);
	// We insert the modified string into the new file
	newFile << fileString;
	// Close the new file
	newFile.close();

	// Check the changesMade flag to see if any changes were made
	if (changesMade == false)
	{
		std::cout << "File \"" << filename << "\" did not contain any matches" << std::endl;
		return 1;
	}

	// If all was successful, return 0	
	return 0;
}

// Function to find and replace all occurrences of s1 with s2 in a string
std::string	findAndReplace(std::string &str, const std::string &s1, const std::string &s2, bool &changesMade)
{
	// Get the position of the first occurrence of s1
	size_t	pos = str.find(s1);
	// If std::string::find returns std::string::npos, it means that the substring was not found
	while (pos != std::string::npos)
	{
		// At the pos position, remove the length of s1 and insert s2
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		// Set the changesMade flag to true
		changesMade = true;
		// Find the next ocurrence of s1, starting from the current pos value + the lenght of s2, to avoid infinite loop
		pos = str.find(s1, pos + s2.length());
	}
	return str;
}

int	checkFile(std::ifstream &file, const std::string filepath)
{
	struct stat	fileStat;

	// We use C's stat to check if the file is a regular file
	stat(filepath.c_str(), &fileStat);


	// If there was an error opening the file
	if (!file.good())
	{
		// Check if the file exists or if it has no read permissions
		if (access(filepath.c_str(), F_OK) == -1)
			std::cout << "The provided file \"" << filepath << "\" does not exist" << std::endl;
		else if (access(filepath.c_str(), R_OK) == -1)
			std::cout << "The provided file \"" << filepath << "\" does not have read permissions" << std::endl;
		return 1;
	}

		// If the filepath does not point to a regular file
	if (S_ISREG(fileStat.st_mode) == 0)
	{
		// If specifically, the file is a directory
		if (S_ISDIR(fileStat.st_mode) == 1)
			std::cout << "The provided file \"" << filepath << "\" is a directory" << std::endl;
		else
			std::cout << "The provided file \"" << filepath << "\" is not a regular file" << std::endl;
		return 1;
	}

	// Check if still, the file was not opened successfully, despite passing all previous checks
	if (!file.is_open())
	{
		std::cout << "Failed to open file \"" << filepath << "\"" << std::endl;
		return 1;
	}
	return 0;
}

int	checkFile(std::ofstream &file, const std::string filepath)
{
	struct stat	fileStat;

	// We use C's stat to check if the file is a regular file
	stat(filepath.c_str(), &fileStat);


	// If there was an error opening the file
	if (!file.good())
	{
		// Check if the file exists or if it has no read permissions
		if (access(filepath.c_str(), F_OK) == -1)
			std::cout << "The provided file \"" << filepath << "\" does not exist" << std::endl;
		else if (access(filepath.c_str(), W_OK) == -1)
			std::cout << "The provided file \"" << filepath << "\" does not have write permissions" << std::endl;
		return 1;
	}

	// If the filepath does not point to a regular file
	if (S_ISREG(fileStat.st_mode) == 0)
	{
		// If specifically, the file is a directory
		if (S_ISDIR(fileStat.st_mode) == 1)
			std::cout << "The provided file \"" << filepath << "\" is a directory" << std::endl;
		else
			std::cout << "The provided file \"" << filepath << "\" is not a regular file" << std::endl;
		return 1;
	}

	// Check if still, the file was not opened successfully, despite passing all previous checks
	if (!file.is_open())
	{
		std::cout << "Failed to open file \"" << filepath << "\"" << std::endl;
		return 1;
	}
	return 0;
}

// Function to store the file content in a string
std::string	storeFile(const std::string filepath)
{
	// Create an ifstream for the file and a stringbuffer for its content
	std::ifstream		file(filepath);
	std::stringstream	buffer;

	// Check for file errors
	if (checkFile(file, filepath))
		return "";

	// Insert the file content into the buffer using std::ifstream::rdbuf()
	buffer << file.rdbuf();
	// Close the file as we no longer need it
	file.close();

	// Check if the file is empty by chekcking the buffer string
	if (buffer.str() == "")
	{
		std::cout << "The provided file \"" << filepath << "\" is empty" << std::endl;
		return "";
	}

	// Return the buffer string
	return (buffer.str());
}
