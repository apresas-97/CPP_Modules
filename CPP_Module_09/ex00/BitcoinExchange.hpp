#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <string>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &other );
		~BitcoinExchange();
		BitcoinExchange &operator=( BitcoinExchange const &other );

	private:
		void	initDataMap( void );

		std::map<std::string, float>	_data;

	public:
		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif // BITCOINEXCHANGE_HPP
