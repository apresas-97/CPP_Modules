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

void	identify( Base* p )
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

void	identify( Base& p )
{
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "Identified type A" << std::endl;
	else if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "Identified type B" << std::endl;
	else if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "Identified type C" << std::endl;
	else
		std::cout << "Failed to identify the type" << std::endl;
}
