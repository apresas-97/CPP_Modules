#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <sstream>

#include <list>
#include <vector>
#include <deque>
#include <map>

class RPN
{
	public:
		RPN( void );
		RPN( RPN const &other );
		~RPN();
		RPN &operator=( RPN const &other );

		void	calculate( std::string const &expression );

	private:

		std::deque<std::string>	tokenize( std::string const &expression );
		std::deque<std::string>	toPostfix( std::deque<std::string> const &tokens );
		std::deque<std::string>	evaluate( std::deque<std::string> const &postfix );
		void	printResult( std::deque<std::string> const &result );

};

#endif // RPN_HPP
