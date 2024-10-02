#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <stack>

#include <exception>

#include <sstream>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &other );
		~BitcoinExchange();
		BitcoinExchange &operator=( BitcoinExchange const &other );

		BitcoinExchange	operator+( BitcoinExchange const & rhs );
		BitcoinExchange	operator-( BitcoinExchange const & rhs );
		BitcoinExchange	operator*( BitcoinExchange const & rhs );
		BitcoinExchange	operator/( BitcoinExchange const & rhs );

		void	loadFile( std::string & filename );
		void	parseFile( std::ifstream & file );
		std::vector<std::pair<std::string, float> >	getVectorFromFile( std::ifstream & file, const std::string divider );

		void	verifyDate( std::string & date );
		long	getDate( std::string & date );
		float	getValue( std::string & value );

		void	setDataVector( void );

		void	checkConversion( std::string & filename );

	class CouldNotOpenFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class BadInputException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class DatePreviousToDataException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:
		std::vector<std::pair<std::string, float> >	_data;

};

#endif // BITCOINEXCHANGE_HPP
