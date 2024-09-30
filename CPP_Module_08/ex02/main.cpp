#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

void	test_constructors( void );
void	vector_stack_test( void );
void	list_stack_test( void );

int	main( void )
{
	test_constructors();
	vector_stack_test();
	list_stack_test();

	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << "mstack.top() = " << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << "mstack.size() = " << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);

	return 0;
}

void	test_constructors( void )
{
	std::cout << ">> CONSTRUCTOR TESTS:" << std::endl;
	try
	{
		std::cout << "Constructing as a MutantStack<int>:" << std::endl;
		MutantStack<int>	mstack;
		std::stack<int>		s(mstack);
		std::cout << "Constructing as a MutantStack<int, std::vector<int>>:" << std::endl;
		MutantStack<int, std::vector<int> >		mstack_vector;
		std::stack<int, std::vector<int> >		s_vector(mstack_vector);
		std::cout << "Constructing as a MutantStack<char, std::list<char>>:" << std::endl;
		MutantStack<char, std::list<char> >		mstack_list;
		std::stack<char, std::list<char> >		s_list(mstack_list);
		std::cout << "Constructing as a MutantStack<float, std::deque<float>>:" << std::endl;
		MutantStack<float, std::deque<float> >	mstack_deque;
		std::stack<float, std::deque<float> >	s_deque(mstack_deque);
		std::cout << "There were no complains when copying MutantStack to std::stack." << std::endl;
	}
	catch( const std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	vector_stack_test( void )
{
	std::cout << ">> VECTOR STACK TEST:" << std::endl;
	std::cout << "std::stack<int, std::vector<int> > vec_stack for reference:" << std::endl;
	std::stack<int, std::vector<int> > vec_stack;
	vec_stack.push(5);
	vec_stack.push(17);
	std::cout << "vec_stack.top() = " << vec_stack.top() << std::endl;
	vec_stack.pop();
	std::cout << "vec_stack.size() = " << vec_stack.size() << std::endl;
	vec_stack.push(3);
	vec_stack.push(5);
	vec_stack.push(737);
	vec_stack.push(0);

	std::cout << "MutantStack<int, std::vector<int> > vec_mstack:" << std::endl;
	MutantStack<int, std::vector<int> > vec_mstack;

	vec_mstack.push(5);
	vec_mstack.push(17);
	std::cout << "vec_mstack.top() = " << vec_mstack.top() << std::endl;
	vec_mstack.pop();
	std::cout << "vec_mstack.size() = " << vec_mstack.size() << std::endl;
	vec_mstack.push(3);
	vec_mstack.push(5);
	vec_mstack.push(737);
	vec_mstack.push(0);

	std::cout << "Testing if vec_mstack is equal to vec_stack:" << std::endl;
	if (vec_mstack == vec_stack)
		std::cout << "vec_mstack == vec_stack" << std::endl;
	else
		std::cout << "vec_mstack != vec_stack" << std::endl;

	std::cout << "Now using iterators to print the contents of vec_mstack:" << std::endl;
	MutantStack<int, std::vector<int> >::iterator it = vec_mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = vec_mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

void	list_stack_test( void )
{
	std::cout << ">> LIST STACK TEST:" << std::endl;
	std::cout << "std::stack<long, std::list<long> > lst_stack for reference:" << std::endl;
	std::stack<long, std::list<long> > lst_stack;
	lst_stack.push(5);
	lst_stack.push(17);
	std::cout << "lst_stack.top() = " << lst_stack.top() << std::endl;
	lst_stack.pop();
	std::cout << "lst_stack.size() = " << lst_stack.size() << std::endl;
	lst_stack.push(3);
	lst_stack.push(5);
	lst_stack.push(737);
	lst_stack.push(0);

	std::cout << "MutantStack<long, std::list<long> > lst_mstack:" << std::endl;
	MutantStack<long, std::list<long> > lst_mstack;

	lst_mstack.push(5);
	lst_mstack.push(17);
	std::cout << "lst_mstack.top() = " << lst_mstack.top() << std::endl;
	lst_mstack.pop();
	std::cout << "lst_mstack.size() = " << lst_mstack.size() << std::endl;
	lst_mstack.push(3);
	lst_mstack.push(5);
	lst_mstack.push(737);
	lst_mstack.push(0);

	std::cout << "Testing if lst_mstack is equal to lst_stack:" << std::endl;
	if (lst_mstack == lst_stack)
		std::cout << "lst_mstack == lst_stack" << std::endl;
	else
		std::cout << "lst_mstack != lst_stack" << std::endl;

	std::cout << "Now using iterators to print the contents of lst_mstack:" << std::endl;
	MutantStack<long, std::list<long> >::iterator it = lst_mstack.begin();
	MutantStack<long, std::list<long> >::iterator ite = lst_mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}
