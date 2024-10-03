#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>

typedef struct s_element
{
	std::string	date;
	float		value;
}				t_element;

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &other );
		~BitcoinExchange();
		BitcoinExchange &operator=( BitcoinExchange const &other );

		void	calculateValues( std::string & filename );
		void	printDataVector( void );

	private:

		void					initDataMap( void );
		std::vector<t_element>	initInputMap( std::string & filename );
		bool					verifyDateFormat( std::string & date );

		std::vector<t_element>	_data;

	public:
		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class InvalidInputHeaderException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif // BITCOINEXCHANGE_HPP
