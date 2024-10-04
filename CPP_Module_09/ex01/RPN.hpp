#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cctype>
#include <deque>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define NUMBER 0

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
		void				easyRPN( std::string const & expression );
	
	private:
		bool				verifyExpression( std::string const & expression );
		std::deque<t_token>	tokenize( std::string const & expression );
		std::deque<t_token>	getSubExpression( std::deque<t_token> & tokenized_expression );
		int					operateSubExpression( std::deque<t_token> & sub_expression );
		void				printDeque( std::deque<t_token> const & deque );

};

#endif // RPN_HPP
