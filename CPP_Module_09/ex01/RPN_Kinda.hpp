#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cctype>

#include <list>
#include <vector>
#include <deque>
#include <map>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

class RPN
{
public:
	RPN( void );
	RPN( RPN const & other );
	~RPN();
	RPN &operator=( RPN const & other );

	void	calculate( std::string const & expression );

private:
	void	simpleApproach( std::string const & expression );
	bool	verifyExpression( std::string const & expression );
	std::deque<char>	tokenize( std::string const & expression );
	std::deque<char>	getSubExpression( std::deque<char> & tokenized_expression );
	void	calculateAndPrint( std::deque<std::string> & deque );
	void	newApproach( std::string const & expression );

	int	operateSubExpression( std::deque<char> & sub_expression, int leftmost_value );

};


#endif // RPN_HPP
