#include "MutantStack.hpp"
#include "tester.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define BLUE "\033[1;34m"
#define BOLD "\033[1m"

void	test_constructors( void );
int		subject_main( void );

int	main( void )
{
	test_constructors();

	std::cout << BLUE "Checking if the outputs of std::stack and MutantStack are the same:" RESET << std::endl;
	test_stack_outputs<int>();
	test_stack_outputs<int, std::vector<int> >();
	test_stack_outputs<char, std::list<char> >();
	test_stack_outputs<float, std::deque<float> >();
	std::cout << std::endl;

	std::cout << BLUE "Checking if the mstack iterators work as expected:" RESET << std::endl;
	test_mstack_iterators<int>();
	test_mstack_iterators<int, std::vector<int> >();
	test_mstack_iterators<float, std::deque<float> >();
	test_mstack_iterators<char, std::list<char> >();
	std::cout << std::endl;

	std::cout << BLUE "Checking if the main from the subject works:" RESET << std::endl;
	subject_main();
	std::cout << std::endl;

	return 0;
}

void	test_constructors( void )
{
	std::cout << BLUE "Checking if the constructors work as expected:" RESET << std::endl;
	try
	{
		MutantStack<int>	mstack;
		std::stack<int>		s(mstack);
		std::stack<int>		s2;
		s2 = mstack;
		MutantStack<int, std::vector<int> >		mstack_vector;
		std::stack<int, std::vector<int> >		s_vector(mstack_vector);
		std::stack<int, std::vector<int> >		s2_vector;
		s2_vector = mstack_vector;
		MutantStack<char, std::list<char> >		mstack_list;
		std::stack<char, std::list<char> >		s_list(mstack_list);
		std::stack<char, std::list<char> >		s2_list;
		s2_list = mstack_list;
		MutantStack<float, std::deque<float> >	mstack_deque;
		std::stack<float, std::deque<float> >	s_deque(mstack_deque);
		std::stack<float, std::deque<float> >	s2_deque;
		s2_deque = mstack_deque;
		std::cout << GREEN "All constructors work as expected." RESET << std::endl;
	}
	catch( const std::exception & e )
	{
		std::cout << RED "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	subject_main( void )
{
	std::cout << BOLD "Using MutantStack:" RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << BOLD "Now using std::list:" RESET << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	return 0;
}
