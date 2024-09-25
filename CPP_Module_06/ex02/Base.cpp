#include "Base.hpp"

Base::~Base()
{

}

Base*	generate( void )
{
	std::srand(std::clock());
	switch (rand() % 3)
	{
		case 0:
		{
			std::cout << "Type created is A" << std::endl; // For clarity
			return new A;
		}
		case 1:
		{
			std::cout << "Type created is B" << std::endl; // For clarity
			return new B;
		}
		default:
		{
			std::cout << "Type created is C" << std::endl; // For clarity
			return new C;
		}
	}
}

void	identify( Base * p )
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Identified type A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Identified type B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identified type C" << std::endl;
	else
		std::cout << "Failed to identify the type" << std::endl;
}

void	identify( Base & p )
{
	try
	{
		A & a = dynamic_cast<A&>(p);
		std::cout << "Identified type A" << std::endl;
		(void)a;
		return ;
	}
	catch ( const std::exception & e ) {}
	try
	{
		B & b = dynamic_cast<B&>(p);
		std::cout << "Identified type B" << std::endl;
		(void)b;
		return ;
	}
	catch ( const std::exception & e ) {}
	try
	{
		C & c = dynamic_cast<C&>(p);
		std::cout << "Identified type C" << std::endl;
		(void)c;
		return ;
	}
	catch ( const std::exception & e ) {}
	std::cout << "Failed to identify the type" << std::endl;
}
