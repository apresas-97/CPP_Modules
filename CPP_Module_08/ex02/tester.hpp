#ifndef TESTER_HPP
#define TESTER_HPP

#include <sstream>
#include <iostream>
#include <stack>
#include "MutantStack.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

template<typename STACK>
void	xstack_test( std::stringstream &ss )
{
	STACK stack;

	// Testing empty, size, top, push and pop
	ss << stack.size() << std::endl;
	ss << stack.empty() << std::endl;
	stack.push(100);
	ss << stack.top() << std::endl;
	stack.push(42);
	ss << stack.empty() << std::endl;
	ss << stack.top() << std::endl;
	ss << stack.size() << std::endl;
	stack.pop();
	ss << stack.top() << std::endl;
	ss << stack.size() << std::endl;
	stack.push(65);
	stack.push(66);
	stack.push(67);
	stack.push(68);
	ss << stack.size() << std::endl;
	stack.push(69);
	stack.push(70);
	stack.push(71);
	stack.pop();
	stack.pop();
	stack.push(72);
	stack.push(73);
	ss << stack.empty() << std::endl;
	ss << stack.top() << std::endl;
	stack.push(74);
	stack.pop();	
	ss << stack.top() << std::endl;
	stack.push(75);
	stack.push(76);
	ss << stack.size() << std::endl;
	stack.push(77);
	stack.push(78);
	stack.push(79);
	ss << stack.size() << std::endl;
	stack.push(80);
	stack.pop();
	stack.pop();
	stack.pop();
	ss << stack.size() << std::endl;
	stack.pop();
	stack.push(81);
	stack.push(82);
	ss << stack.size() << std::endl;
	ss << stack.top() << std::endl;

	// Testing operator=
	STACK stack2 = stack;
	ss << stack2.size() << std::endl;
	ss << stack2.top() << std::endl;
	stack2.pop();
	ss << stack2.size() << std::endl;
	ss << stack2.top() << std::endl;
	ss << stack.size() << std::endl;
	ss << stack.top() << std::endl;

	// Testing copy constructor
	STACK stack3(stack);
	ss << stack3.size() << std::endl;
	ss << stack3.top() << std::endl;
	stack3.pop();
	ss << stack3.size() << std::endl;
	ss << stack3.top() << std::endl;
	ss << stack.size() << std::endl;
	ss << stack.top() << std::endl;
}

template<typename T>
void	test_stack_outputs( void )
{
	std::stringstream ss_stack;
	std::stringstream ss_mstack;
	xstack_test<std::stack<T> >(ss_stack);
	xstack_test<MutantStack<T> >(ss_mstack);
	if (ss_stack.str() == ss_mstack.str())
		std::cout << GREEN "Equal outputs." RESET << std::endl;
	else
		std::cout << RED "Different outputs." RESET << std::endl;
}

template<typename T, typename Container>
void	test_stack_outputs( void )
{
	std::stringstream ss_stack;
	std::stringstream ss_mstack;
	xstack_test<std::stack<T, Container> >(ss_stack);
	xstack_test<MutantStack<T, Container> >(ss_mstack);
	if (ss_stack.str() == ss_mstack.str())
		std::cout << GREEN "Equal outputs." RESET << std::endl;
	else
		std::cout << RED "Different outputs." RESET << std::endl;
}

template<typename T>
void	test_mstack_iterators( void )
{
	MutantStack<T> mstack;
	mstack.push('H');
	mstack.push('o');
	mstack.push('l');
	mstack.push('a');
	mstack.push('!');

	std::cout << "Testing iterators:" << std::endl;
	std::stringstream ss;

	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();
	while (it != ite)
	{
		ss << *it << " ";
		++it;
	}
	std::cout << ss.str() << std::endl;
	std::cout << std::endl;
}

template<typename T, typename Container>
void	test_mstack_iterators( void )
{
	MutantStack<T, Container> mstack;
	mstack.push('H');
	mstack.push('o');
	mstack.push('l');
	mstack.push('a');
	mstack.push('!');

	std::cout << "Testing iterators:" << std::endl;
	std::stringstream ss;

	typename MutantStack<T, Container>::iterator it = mstack.begin();
	typename MutantStack<T, Container>::iterator ite = mstack.end();
	while (it != ite)
	{
		ss << *it << " ";
		++it;
	}
	std::cout << ss.str() << std::endl;
	std::cout << std::endl;
}

#endif // TESTER_HPP