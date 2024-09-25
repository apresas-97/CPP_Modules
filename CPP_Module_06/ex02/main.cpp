#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void )
{
	std::cout << "Identifying generated object:" << std::endl;
	// We generate a random class derived from Base
	Base* base = generate();
	// We identify the class using a pointer
	identify(base);
	// We identify the class using a reference
	identify(*base);
	delete base;
	std::cout << "----------------------------------------" << std::endl;
	
	// We can also do it with objects in the stack
	A a;
	B b;
	C c;
	std::cout << "Identifying A:" << std::endl;
	identify(&a);
	identify(a);
	std::cout << "Identifying B:" << std::endl;
	identify(&b);
	identify(b);
	std::cout << "Identifying C:" << std::endl;
	identify(&c);
	identify(c);
	std::cout << "----------------------------------------" << std::endl;

	// If we try to identify a Base object, it will fail
	std::cout << "Identifying Base:" << std::endl;
	Base base2;
	identify(&base2);
	identify(base2);
	std::cout << "----------------------------------------" << std::endl;

	// Even if we pass it as a Base*, it will identify it as the correct type
	std::cout << "Identifying as Base*:" << std::endl;
	std::cout << "Identifying A:" << std::endl;
	A a2;
	Base *baseptr = &a2;
	identify(baseptr);
	identify(*baseptr);
	std::cout << "Identifying B:" << std::endl;
	B b2;
	baseptr = &b2;
	identify(baseptr);
	identify(*baseptr);
	std::cout << "Identifying C:" << std::endl;
	C c2;
	baseptr = &c2;
	identify(baseptr);
	identify(*baseptr);

	return 0;
}
