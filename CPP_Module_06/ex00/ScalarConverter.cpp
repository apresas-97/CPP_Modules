#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	// This class is not instantiable
}

ScalarConverter::ScalarConverter( ScalarConverter const &other )
{
	// This class is not instantiable
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	// This class is not instantiable
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other )
{
	// This class is not instantiable
	if ( this != &other )
	{

	}
	return *this;
}

int	ScalarConverter::get_meaningful_decimals( const std::string & input )
{
	size_t	i = 0;
	size_t	decimals = 0;
	size_t	zeroes = 0;

	while (i < input.size() && input[i] != '.')
		i++;
	if (i == input.size())
		return 1;
	i++;
	while (i < input.size() && input[i] == '0')
	{
		zeroes++;
		i++;
	}
	if (zeroes > 5 || i == input.size() || input[i] == 'f')
		return 1;
	decimals = zeroes;
	while (i < input.size() && input[i] != 'f' && decimals < 6)
	{
		if (input[i] == '0')
		{
			zeroes = 0;
			while (i < input.size() && input[i] == '0')
			{
				zeroes++;
				i++;
			}
			if (decimals + zeroes >= 6 || i == input.size())
				return decimals;
			decimals += zeroes;
		}
		else
		{
			decimals++;
			i++;
		}
	}
	return decimals;
}

bool	ScalarConverter::input_is_int( const std::string & input )
{
	char	*endptr = NULL;
	long	 aux = std::strtol(input.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return false;
	if (aux > INT_MAX || aux < INT_MIN)
		return false;
	return true;
}

bool	ScalarConverter::input_is_float( const std::string & input )
{
	char	*endptr = NULL;
	if (input.empty() == true)
		return false;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (std::isdigit(input[0]) == false && input[0] != '-' && input[0] != '+' && input[0] != '.')
		return false;
	if (input.find('.') == std::string::npos)
		return false;
	std::strtof(input.c_str(), &endptr);
	if (*endptr != 'f' || &input[input.size() - 1] != endptr)
		return false;
	return true;
}

bool	ScalarConverter::input_is_double( const std::string & input )
{
	char	*endptr = NULL;
	if (input.empty() == true)
		return false;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (std::isdigit(input[0]) == false && input[0] != '-' && input[0] != '+' && input[0] != '.')
		return false;
	if (input.find('.') == std::string::npos)
		return false;
	std::strtod(input.c_str(), &endptr);
	if (*endptr != '\0')
		return false;
	return true;
}

void	ScalarConverter::display_char( const char c , const long l )
{
	if (l > 255 || l < 0)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	ScalarConverter::display_int( const int i, const long l )
{
	if (l > INT_MAX || l < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::display_float( const float f, const int decimals )
{
	std::cout << "float: " << std::fixed << std::setprecision(decimals) << f << "f" << std::endl;
}

void	ScalarConverter::display_double( const double d, const int decimals )
{
	std::cout << "double: " << std::fixed << std::setprecision(decimals) << d << std::endl;
}

void	ScalarConverter::convert( const std::string & input )
{
	if (input.empty() == true)
		throw ScalarConverter::EmptyInput();
	char		charValue = 0;
	int			intValue = 0;
	float		floatValue = 0;
	double		doubleValue = 0;
	long		longValue = 0;
	if (input.size() == 1)
	{
		charValue = input[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
		longValue = static_cast<long>(charValue);
	}
	else if (input_is_int(input))
	{
		intValue = std::atoi(input.c_str());
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
		longValue = static_cast<long>(intValue);
	}
	else if (input_is_float(input))
	{
		floatValue = std::strtof(input.c_str(), NULL);
		charValue = static_cast<char>(floatValue);
		intValue = static_cast<int>(floatValue);
		doubleValue = static_cast<double>(floatValue);
		longValue = static_cast<long>(floatValue);
	}
	else if (input_is_double(input))
	{
		doubleValue = std::strtod(input.c_str(), NULL);
		charValue = static_cast<char>(doubleValue);
		intValue = static_cast<int>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
		longValue = static_cast<long>(doubleValue);
	}
	else
		throw ScalarConverter::WrongInput();
	int meaningful_decimals = get_meaningful_decimals(input);
	display_char(charValue, intValue);
	display_int(intValue, longValue);
	display_float(floatValue, meaningful_decimals);
	display_double(doubleValue, meaningful_decimals);
}

// Exceptions
const char*	ScalarConverter::WrongInput::what() const throw()
{
	return ("Wrong input");
}

const char*	ScalarConverter::EmptyInput::what() const throw()
{
	return ("Empty input");
}
