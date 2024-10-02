#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	// std::cout << "BitcoinExchange default constructor called" << std::endl;
	setDataVector();
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

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if ( this != &other )
	{

	}
	return *this;
}

void	BitcoinExchange::checkConversion( std::string & filename )
{
	std::ifstream file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw CouldNotOpenFileException();
	else
		std::cout << filename << " opened succesfully" << std::endl;
	std::vector<std::pair<std::string, float> > input = getVectorFromFile(file, " | ");
	std::sort(input.begin(), input.end());

	std::vector<std::pair<std::string, float> >::iterator it = input.begin();
	std::vector<std::pair<std::string, float> >::iterator it_data;
	while (it != input.end())
	{
		// while (it_data != this->_data.end())
		// {
		// 	if (it->first <= it_data->first)
		// 	{
		// 		if (it->first == it_data->first)
		// 		{
		// 			// std::cout << "Found (input)" << it->first << " => " << it->second << " | (data.csv)" << it_data->first << " => " << it_data->second << std::endl;
		// 			// std::cout << it->first << " => " << it->second << " | " << (it_data->second * it->second) << std::endl;
		// 			std::cout << it->first << " => " << it->second << " | " << it_data->second << " * " << it->second << " = "  << (it_data->second * it->second) << std::endl;
		// 		}
		// 		else
		// 		{
		// 			if (it_data != this->_data.begin())
		// 				it_data--;
		// 			// std::cout << "Found (input)" << it->first << " => " << it->second << " | (data.csv)" << it_data->first << " => " << it_data->second << std::endl;
		// 			// std::cout << it->first << " => " << it->second << " | " << (it_data->second * it->second) << std::endl;
		// 			std::cout << it->first << " => " << it->second << " | " << it_data->second << " * " << it->second << " = "  << (it_data->second * it->second) << std::endl;
		// 		}
		// 		break ;
		// 	}
		// 	it_data++;
		// }
		it_data = this->_data.begin();
		while (it_data != this->_data.end())
		{
			if (it->first <= it_data->first)
			{
				if (it->first == it_data->first)
				{
					std::cout << it->first << " => " << it->second << " | " << it_data->second << " * " << it->second << " = "  << (it_data->second * it->second) << std::endl;
				}
				else
				{
					if (it_data != this->_data.begin())
						it_data--;
					std::cout << it->first << " => " << it->second << " | " << it_data->second << " * " << it->second << " = "  << (it_data->second * it->second) << std::endl;
				}
				break ;
			}
			it_data++;
		}

		it++;
	}
}

void	BitcoinExchange::loadFile( std::string & filename )
{
	std::ifstream file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw CouldNotOpenFileException();
	std::vector<std::pair<std::string, float> > input = getVectorFromFile(file, " | ");
}

void	BitcoinExchange::setDataVector( void )
{
	std::vector<std::pair<std::string, float> > data;
	std::string line;
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw CouldNotOpenFileException();

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string exchange_rate_str;
		date = line.substr(0, 10);
		exchange_rate_str = line.substr(11);
		float	exchange_rate;
		std::stringstream ss(exchange_rate_str);
		ss >> exchange_rate;
		data.push_back(std::pair<std::string, float>());
		data.back().first = date;
		data.back().second = exchange_rate;
	}
	this->_data = data;
}

std::vector<std::pair<std::string, float> >	BitcoinExchange::getVectorFromFile( std::ifstream & file, const std::string divider )
{
	std::vector<std::pair<std::string, float> > data;
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::invalid_argument("Invalid file header?");
	while (std::getline(file, line))
	{
		std::string date;
		std::string value_str;
		std::string::size_type pos = line.find(divider);
		if (pos == std::string::npos)
			date = "Invalid";
		else
		{
			date = line.substr(0, pos);
			value_str = line.substr(pos + divider.size());
		}

		float	value;
		try
		{
			verifyDate(date);
			value = getValue(value_str);
			data.push_back(std::pair<std::string, float>());
			data.back().first = date;
			data.back().second = value;
		}
		catch ( const std::exception & e )
		{
			std::cout << e.what() << " => "  << line << std::endl;
		}
	}
	return data;
}

float	BitcoinExchange::getValue( std::string & value_str )
{
	std::stringstream	ss(value_str);
	float	value;

	if (!std::isdigit(value_str[0]))
		throw BadInputException();
	if (!(ss >> value))
		throw BadInputException();
	if (value < 0.0 || value > 1000.0)
		throw BadInputException();
	if (ss.peek() != EOF)
		throw BadInputException();
	return value;
}

// long	BitcoinExchange::getDate( std::string & date )
// {
// 	verifyDate(date);
// 	std::stringstream ss(date);
// 	int year, month, day;
// 	ss >> year >> month >> day;
// 	return year * 10000 + month * 100 + day;
// }

void	BitcoinExchange::verifyDate( std::string & date )
{
	if (date.size() != 10)
		throw BadInputException();
	if (date[4] != '-' || date[7] != '-')
		throw BadInputException();
	date[4] = ' ';
	date[7] = ' ';
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (std::isdigit(date[i]) == 0)
			throw BadInputException();
	}
	std::stringstream ss(date);
	int year, month, day;
	if (!(ss >> year >> month >> day))
		throw BadInputException();
	if (month < 1 || month > 12)
		throw BadInputException();
	if (day < 1)
		throw BadInputException();
	if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
		throw BadInputException();
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		throw BadInputException();
	if (day > 29 && month == 2)
		throw BadInputException();
	if (day == 29 && month == 2 && year % 4 != 0)
		throw BadInputException();
	if (day == 29 && month == 2 && year % 100 == 0 && year % 400 != 0)
		throw BadInputException();
	if (date < "2009-01-02")
		throw DatePreviousToDataException();
	date[4] = '-';
	date[7] = '-';
}

// Exceptions
const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return "Error: could not open file";
}

const char	*BitcoinExchange::BadInputException::what() const throw()
{
	return "Error: bad input";
}

const char	*BitcoinExchange::DatePreviousToDataException::what() const throw()
{
	return "Error: date previous to minimum data date (2009-01-02)";
}
