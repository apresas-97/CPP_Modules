#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	// Irrelevant, this class is not instantiable
}

ScalarConverter::ScalarConverter( ScalarConverter const &other )
{
	// Irrelevant, this class is not instantiable
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	// Irrelevant, this class is not instantiable
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other )
{
	// Irrelevant, this class is not instantiable
	if ( this != &other )
	{

	}
	return *this;
}

int	get_floating_point_meaningful_digits( float f )
{
	// Converting float to string (c++98)
	std::stringstream	ss;
	ss << f;
	std::string	str = ss.str();
	std::cout << "str: " << str << std::endl;
	std::cout << "str.size(): " << str.size() << std::endl;
	return str.size();
}

bool	string_is_int( const std::string & str )
{
	char	*endptr = NULL;
	long aux = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return false;
	if (aux > INT_MAX || aux < INT_MIN)
		return false;
	return true;

	size_t	i = 0;
	if (str.empty() == true)
		return false;
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	if (i == str.size())
		return false;
	while (i < str.size() && str[i] == '0')
		i++;
	if (i == str.size())
		return true;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return false;
	}
	if (str[0] == '-' && str.size() == 11 && str.compare("-2147483648") > 0)
		return false;
	else if (str[0] == '+' && str.size() == 11 && str.compare("+2147483647") > 0)
		return false;
	else if (str.size() == 10 && str.compare("2147483647") > 0)
		return false;
	else if (str.size() > 11)
		return false;
	return true;
}

bool	string_is_float(std::string str )
{
	// Maybe?
	if (str.empty() == true)
		return false;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	char	*endptr = NULL;
	std::strtof(str.c_str(), &endptr);
	if (*endptr != 'f' || &str[str.size() - 1] != endptr)
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	return true;
}

bool	string_is_double( std::string str )
{
	if (str.empty() == true)
		return false;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	char	*endptr = NULL;
	std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	return true;
}

void	ScalarConverter::convert( const std::string & input )
{
	if (input.empty() == true)
		throw ScalarConverter::EmptyInput(); //? Maybe just display "Empty input" and return
	
	std::cout << ">Input: " << input << std::endl;
	char		charValue = 0;
	int			intValue = 0;
	float		floatValue = 0;
	double		doubleValue = 0;
	// long 		longValue = 0;
	std::string	charOutput;
	std::string	intOutput;
	std::string	floatOutput;
	std::string	doubleOutput;
	if (input.size() == 1)
	{
		std::cout << "CHAR" << std::endl;
		if (std::isprint(input[0]) == false)
			charOutput = "Non displayable";
		else
			charOutput = input;
		std::cout << "char: '" << charOutput << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		// std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
		// std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
	else if (string_is_int(input))
	{
		std::cout << "INT" << std::endl;
		intValue = std::atoi(input.c_str());
		if (intValue > 255 || intValue < 0)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<char>(intValue)) == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::stringstream	ss;
		ss << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f\n";
		ss << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << "\n";
		std::cout << ss.str() << std::endl;
		//  << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
		// std::cout << 
		// std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
		// std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
		// std::cout.unsetf(std::ios::fixed);
	}
	else if (string_is_float(input))
	{
		std::cout << "FLOAT" << std::endl;
		floatValue = std::strtof(input.c_str(), NULL);
		intValue = static_cast<int>(floatValue);
		// longValue = static_cast<long>(floatValue);
		// std::cout << "LONG: " << longValue << std::endl;
		if (intValue > 255 || intValue < 0)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<char>(floatValue)) == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
		if (floatValue <= 2147483583.0f && floatValue >= -2147483776.0f)
			std::cout << "int: " << intValue << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		int meaningfulDigits = 12;
		// if (floatValue >= 100000.0f)
		// 	meaningfulDigits = 6;
		// else if ()
		// else
		// 	meaningfulDigits = get_floating_point_meaningful_digits(floatValue);
		std::stringstream	ss;
		ss << "float: " << floatValue << "f\n";
		ss << "double: " << static_cast<double>(floatValue) << "\n";
		std::cout << ss.str() << std::endl;
		// std::cout << "float: " << std::fixed << std::setprecision(meaningfulDigits) << floatValue << "f" << std::endl;
		// std::cout << "double: " << std::setprecision(meaningfulDigits) << static_cast<double>(floatValue) << std::endl;
	}
	else if (string_is_double(input))
	{
		std::cout << "DOUBLE" << std::endl;
		doubleValue = std::strtod(input.c_str(), NULL);
		intValue = static_cast<int>(doubleValue);
		// longValue = static_cast<long>(doubleValue);
		if (intValue > 255 || intValue < 0)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<char>(doubleValue)) == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
		if (doubleValue <= 2147483647.0 && doubleValue >= -2147483648.0)
			std::cout << "int: " << intValue << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		// std::cout << "float: " << std::setprecision(6) << static_cast<float>(doubleValue) << "f" << std::endl;
		// std::cout << "double: " << std::setprecision(6) << doubleValue << std::endl;
	}
	else
		std::cout << "Wrong input" << std::endl;
		// throw ScalarConverter::WrongInput();
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
