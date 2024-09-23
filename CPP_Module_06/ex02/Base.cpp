#include "Base.hpp"

Base::~Base()
{

}

Base*	Base::generate( void )
{
	std::srand(std::clock());
	int rand_result = rand() % 3;
	if (rand_result == 0)
		return new A;
	else if (rand_result == 1)
		return new B;
	return new C;
}

void	Base::identify( Base* p )
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "Identified type A" << std::endl;
	else if (b != NULL)
		std::cout << "Identified type B" << std::endl;
	else if (c != NULL)
		std::cout << "Identified type C" << std::endl;
	else
		std::cout << "Failed to identify the type" << std::endl;
}

void	Base::identify( Base& p )
{
	try
	{
		A& a = dynamic_cast<A&>(p);
	}
	catch ( const std::exception & e )
	{
		std::cout << "caught exception: " << e.what() << std::endl;
	}
}
