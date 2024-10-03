#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	// std::cout << "BitcoinExchange default constructor called" << std::endl;
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
		this->_data = other._data;
	}
	return *this;
}

void	BitcoinExchange::calculateValues( std::string & filename )
{
	std::vector<t_element>	input;
	try
	{
		input = initInputMap(filename);
	}
	catch( const std::exception & e )
	{
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}

	std::vector<t_element>::iterator	it = input.begin();
	std::vector<t_element>::iterator	it_data = this->_data.begin();
	while (it != input.end())
	{
		if (it->date.compare(0, 6, "Error:") == 0)
		{
			std::cout << it->date << std::endl;
			it++;
			continue;
		}
		it_data = this->_data.begin();
		if (it->date < it_data->date)
		{
			std::cout << it->date << " => " << it->value << " = " << "No exchange references." << std::endl;
			it++;
			continue;
		}
		while (it_data != this->_data.end())
		{
			if (it->date <= it_data->date)
			{
				if (it->date < it_data->date && it_data != this->_data.begin())
					it_data--;
				std::cout << it->date << " => " << it->value << " = " << (it->value * it_data->value) << std::endl;
				break;
			}
			it_data++;
		}
		if (it_data == this->_data.end())
		{
			it_data--;
			std::cout << it->date << " => " << it->value << " = " << (it->value * it_data->value) << std::endl;
		}
		it++;
	}
}

void	BitcoinExchange::printDataVector( void )
{
	std::vector<t_element>::iterator	it = this->_data.begin();
	while (it != this->_data.end())
	{
		std::cout << it->date << " => " << it->value << std::endl;
		it++;
	}
}

void	BitcoinExchange::initDataMap( void )
{
	std::ifstream file;
	std::vector<t_element>	data;

	file.open("data.csv");
	if (!file.is_open())
		throw OpenFileException();

	std::string line;
	getline(file, line);
	while (getline(file, line))
	{
		t_element			element;
		std::string			date;
		float				value;
		date = line.substr(0, 10);
		std::stringstream	ss(line.substr(11));
		ss >> value;
		element.date = date;
		element.value = value;
		data.push_back(element);
	}
	this->_data = data;
}

std::vector<t_element>	BitcoinExchange::initInputMap( std::string & filename )
{
	std::vector<t_element>	input;
	std::ifstream	file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw OpenFileException();

	std::string line;
	getline(file, line);
	if (line != "date | value")
		throw InvalidInputHeaderException(); // Maybe?
	std::string	divisor = " | ";
	while (getline(file, line))
	{
		t_element				element;
		std::string				value_str;
		std::string::size_type	pos = line.find(divisor);
		if (line.size() < 14 || pos == std::string::npos)
		{
			element.date = "Error: bad input => " + line;
			element.value = 0.0f;
			input.push_back(element);
			continue;
		}
		element.date = line.substr(0, pos);
		value_str = line.substr(pos + divisor.size());

		if (verifyDateFormat(element.date) == false)
		{
			element.date = "Error: bad input => " + line;
			element.value = 0.0f;
			input.push_back(element);
			continue;
		}
		std::stringstream	ss(value_str);
		ss >> element.value;
		if (ss.fail() || !ss.eof())
		{
			element.date = "Error: bad input => " + line;
			element.value = 0.0f;
			input.push_back(element);
			continue;
		}
		if (element.value < 0)
			element.date = "Error: not a positive number.";
		else if (element.value > 1000)
			element.date = "Error: too large a number.";
		input.push_back(element);
	}

	return input;
}

bool	BitcoinExchange::verifyDateFormat( std::string & date )
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (std::isdigit(date[i]) == 0)
			return false;
	}
	std::stringstream	ss(date);
	unsigned int		year, month, day;
	char				dash;
	ss >> year >> dash >> month >> dash >> day;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (day > 28 && month == 2 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
		return false;
	if (day > 29 && month == 2)
		return false;
	return true;
}

// Exceptions
const char*	BitcoinExchange::OpenFileException::what() const throw()
{
	return "Could not open file.";
}

const char*	BitcoinExchange::InvalidInputHeaderException::what() const throw()
{
	return "Invalid input header.";
}
