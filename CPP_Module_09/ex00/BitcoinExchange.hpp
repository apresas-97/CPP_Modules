#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &other );
		~BitcoinExchange();
		BitcoinExchange &operator=( BitcoinExchange const &other );

		void	calculateValues( std::string & filename );

		void	printDataMap( void );
		void	printMap( std::multimap<std::string, float> & map );

	private:

		void								initDataMap( void );
		int									countInputLines( std::string const & filename );
		std::multimap<std::string, float>	initInputMap( std::string & filename );
		bool								verifyDateFormat( std::string & date );

		std::multimap<std::string, float>	_data;

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
