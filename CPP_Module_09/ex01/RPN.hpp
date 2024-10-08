#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <deque>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define NUMBER 0
#define OPERATOR 1

typedef struct s_token
{
	int			value;
	int			flag;
}				t_token;

class RPN
{
public:
	RPN( void );
	RPN( RPN const &other );
	~RPN();
	RPN &operator=( RPN const &other );

	void				calculate( std::string const & expression );
	
private:
	bool				verifyExpressionSyntax( std::string const & expression );
	std::deque<t_token>	tokenize( std::string const & expression );

};

#endif // RPN_HPP
