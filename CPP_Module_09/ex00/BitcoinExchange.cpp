#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	// std::cout << "BitcoinExchange default constructor called" << std::endl;

	// First we need to load the data from the file
	initDataMap();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &other )
{
	// std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &other )
{
	if ( this != &other )
	{

	}
	return *this;
}

void	BitcoinExchange::initDataMap( void )
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw OpenFileException();

	std::string line;
	while (getline(file, line))
	{
		std::string date = line.substr(0, 10);
		std::stringstream	ss(line.substr(11));
		this->_data.insert(std::pair<std::string, float>(date, 0));
		ss >> this->_data[date];
	}
}

std::map<std::string, float>	BitcoinExchange::initInputMap( std::string & filename )
{
	std::ifstream file(filename);

	if (!file.is_open())
		throw OpenFileException();

	// Here goes all the logic to parse the input
	// DO NOT BE TOO NITPICKY ABOUT VALID INPUTS!

	return input;
}

void	BitcoinExchange::CompareData( std::string & filename )
{
	std::map<std::string, float>	input = initInputMap(filename);
}

// Exceptions
const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return "Could not open file";
}