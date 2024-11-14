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
	std::multimap<std::string, float>	input;
	try
	{
		input = initInputMap(filename);
	}
	catch( const std::exception & e )
	{
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}

	std::multimap<std::string, float>::iterator	it = input.begin();
	std::multimap<std::string, float>::iterator	it_data = this->_data.begin();
	while (it != input.end())
	{
		std::string::size_type	pos = it->first.find("|");
		std::string it_date = it->first;
		it_date.erase(0, pos + 1);
		if (it_date.compare(0, 6, "Error:") == 0)
		{
			std::cout << it_date << std::endl;
			it++;
			continue;
		}
		it_data = this->_data.begin();
		if (it_date < it_data->first)
		{
			std::cout << it_date << " => " << it->second << " = " << "No exchange references." << std::endl;
			it++;
			continue;
		}
		while (it_data != this->_data.end())
		{
			if (it_date <= it_data->first)
			{
				if (it_date < it_data->first && it_data != this->_data.begin())
					it_data--;
				std::cout << it_date << " => " << it->second << " = " << (it->second * it_data->second) << std::endl;
				break;
			}
			it_data++;
		}
		if (it_data == this->_data.end())
		{
			it_data--;
			std::cout << it_date << " => " << it->second << " = " << (it->second * it_data->second) << std::endl;
		}
		it++;
	}
}

void	BitcoinExchange::printDataMap( void )
{
	std::multimap<std::string, float>::iterator	it = this->_data.begin();
	while (it != this->_data.end())
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}
}

void	BitcoinExchange::printMap( std::multimap<std::string, float> & map )
{
	std::multimap<std::string, float>::iterator	it = map.begin();
	while (it != map.end())
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}
}

int		BitcoinExchange::countInputLines( std::string const & filename )
{
	std::ifstream	file;
	std::string		line;
	int				count = 0;

	file.open(filename.c_str());
	if (!file.is_open())
		throw OpenFileException();

	getline(file, line);
	while (getline(file, line))
		count++;
	file.close();
	return count;
}


void	BitcoinExchange::initDataMap( void )
{
	std::ifstream						file;
	std::multimap<std::string, float>	data;

	file.open("data.csv");
	if (!file.is_open())
		throw OpenFileException();

	std::string	line;
	getline(file, line);
	while (getline(file, line))
	{
		std::pair<std::string, float>	element;
		std::string			date;
		float				value;
		date = line.substr(0, 10);
		std::stringstream	ss(line.substr(11));
		ss >> value;
		element.first = date;
		element.second = value;
		data.insert(element);
	}
	file.close();
	this->_data = data;
}

std::multimap<std::string, float>	BitcoinExchange::initInputMap( std::string & filename )
{
	std::ifstream						file;
	std::multimap<std::string, float>	input;
	int									input_size = countInputLines(filename);
	int									width = input_size / 10 + 2;

	file.open(filename.c_str());
	if (!file.is_open())
		throw OpenFileException();

	int			i = 0;
	std::string	line;
	getline(file, line);
	if (line != "date | value")
	{
		file.clear();
		file.seekg(0, std::ios::beg);
	}
	std::string	divisor = " | ";
	while (getline(file, line))
	{
		i++;
		std::pair<std::string, float>		element;

		std::stringstream	ss_aux;
		ss_aux << std::setw(width) << std::setfill('0') << i;
		std::string	i_str = ss_aux.str() + "|";

		std::string							value_str;
		std::string							date_str;
		std::string::size_type				pos = line.find(divisor);
		if (line.size() < 14 || pos == std::string::npos)
		{
			element.first = i_str + "Error: bad input => " + line;
			element.second = 0.0f;
			input.insert(element);
			continue;
		}
		date_str = line.substr(0, pos);
		value_str = line.substr(pos + divisor.size());

		if (verifyDateFormat(date_str) == false)
		{
			element.first = i_str + "Error: bad input => " + line;
			element.second = 0.0f;
			input.insert(element);
			continue;
		}
		element.first = i_str + date_str;
		std::stringstream	ss(value_str);
		ss >> element.second;
		if (ss.fail() || !ss.eof())
		{
			element.first = i_str + "Error: bad input => " + line;
			element.second = 0.0f;
			input.insert(element);
			continue;
		}
		if (element.second < 0)
			element.first = i_str + "Error: not a positive number.";
		else if (element.second > 1000)
			element.first = i_str + "Error: too large a number.";
		input.insert(element);
	}
	file.close();
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
