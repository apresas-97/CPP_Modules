#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
// #define RED "\033[31m" // Unused
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
// #define BLUE "\033[34m" // Unused
// #define MAGENTA "\033[35m" // Unused
#define CYAN "\033[36m"
#define BR_RED "\033[91m"
#define BR_GREEN "\033[92m"
#define BR_YELLOW "\033[93m"
#define BR_BLUE "\033[94m" // Unused
#define BR_MAGENTA "\033[95m"
#define BR_CYAN "\033[96m"
#define BR_WHITE "\033[97m"
// #define B_YELLOW BOLD YELLOW // Unused
#define COMMENT ITALIC GREEN
#define TITLE RESET BOLD CYAN
#define CODE RESET ITALIC BR_WHITE
#define CLASS_F BOLD BR_GREEN
#define FUNCTION_F BR_YELLOW
#define OUTPUT_F RESET DIM
#define KEYWORD_F BR_MAGENTA

int	main( void )
{
	std::cout << TITLE ">> Constructing: <<" << std::endl;
	std::cout << RESET COMMENT "// Animal object in Animal* pointer" << std::endl;
	std::cout << CODE CLASS_F "Animal* " CODE "genericAnimal = " KEYWORD_F "new " BR_GREEN "Animal" CODE "();" OUTPUT_F << std::endl;
	const Animal* genericAnimal = new Animal();
	std::cout << std::endl;
	std::cout << RESET COMMENT "// Dog object in Animal* pointer" << std::endl;
	std::cout << CODE CLASS_F "Animal* " CODE "dogAnimal = " KEYWORD_F "new " BR_GREEN "Dog" CODE "();" OUTPUT_F << std::endl;
	const Animal* dogAnimal = new Dog();
	std::cout << std::endl;
	std::cout << RESET COMMENT "// Cat object in Animal* pointer" << std::endl;
	std::cout << CODE CLASS_F "Animal* " CODE "catAnimal = " KEYWORD_F "new " BR_GREEN "Cat" CODE "();" OUTPUT_F << std::endl;
	const Animal* catAnimal = new Cat();
	std::cout << std::endl;
	std::cout << RESET COMMENT "// WrongAnimal object in WrongAnimal* pointer" << std::endl;
	std::cout << CODE CLASS_F "WrongAnimal* " CODE "wrongAnimal = " KEYWORD_F "new " BR_GREEN "WrongCat" CODE "();" OUTPUT_F << std::endl;
	const WrongAnimal* wrongAnimal = new WrongCat();
	std::cout << std::endl;
	std::cout << RESET COMMENT "// WrongCat object in WrongCat* pointer" << std::endl;
	std::cout << CODE CLASS_F "WrongCat* " CODE "wrongCat = " KEYWORD_F "new " BR_GREEN "WrongCat" CODE "();" OUTPUT_F << std::endl;
	const WrongCat *wrongCat = new WrongCat();
	std::cout << RESET << std::endl;


	std::cout << TITLE ">> Testing getType(): <<" RESET << std::endl;
	std::cout << CODE "dogAnimal->" FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << dogAnimal->getType() << CODE "\"" << std::endl;
	std::cout << COMMENT "// Should be \"Dog\", because it's a Dog object, even if casted as Animal*" RESET << std::endl;
	std::cout << std::endl;
	std::cout << CODE "catAnimal->" FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << catAnimal->getType() << CODE "\"" << std::endl;
	std::cout << COMMENT "// Should be \"Cat\", because it's a Cat object, even if casted as Animal*" RESET << std::endl;
	std::cout << std::endl;
	std::cout << CODE "genericAnimal->" FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << genericAnimal->getType() << CODE "\"" << std::endl;
	std::cout << COMMENT "// Should be \"typeless\", because it's an Animal object" RESET << std::endl;
	std::cout << std::endl;
	std::cout << CODE "wrongAnimal->" FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << wrongAnimal->getType() << CODE "\"" << std::endl;
	std::cout << COMMENT "// Should be \"WrongCat\", because it's a WrongCat object, even if casted as WrongAnimal*" RESET << std::endl;
	std::cout << std::endl;
	std::cout << CODE "wrongCat->" FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << wrongCat->getType() << CODE "\"" << std::endl;
	std::cout << COMMENT "// Should be \"WrongCat\", because it's a WrongCat object" RESET << std::endl;
	std::cout << std::endl;

	std::cout << TITLE ">> Testing makeNoise(): <<" RESET << std::endl;
	std::cout << CODE "catAnimal->" FUNCTION_F "makeSound" CODE "() " COMMENT "// Will output the cat sound" RESET BR_BLUE << std::endl;
	catAnimal->makeSound();
	std::cout << std::endl;
	std::cout << CODE "dogAnimal->" FUNCTION_F "makeSound" CODE "() " COMMENT "// Will output the dog sound" RESET BR_BLUE << std::endl;	
	dogAnimal->makeSound();
	std::cout << std::endl;
	std::cout << CODE "genericAnimal->" FUNCTION_F "makeSound" CODE "() " COMMENT "// Will output the generic sound" RESET BR_BLUE << std::endl;
	genericAnimal->makeSound();
	std::cout << std::endl;
	std::cout << CODE "wrongAnimal->" FUNCTION_F "makeSound" CODE "() " COMMENT "// Will incorrectly output the generic sound" RESET BR_BLUE << std::endl;
	wrongAnimal->makeSound();
	std::cout << std::endl;
	std::cout << CODE "wrongCat->" FUNCTION_F "makeSound" CODE "() " COMMENT "// Will make a cat sound as it's of type WrongCat" RESET BR_BLUE << std::endl;
	wrongCat->makeSound();
	std::cout << RESET << std::endl;

	std::cout << TITLE ">> Deleting pointers: <<" << std::endl;
	std::cout << RESET KEYWORD_F "delete " CODE "catAnimal;" OUTPUT_F << std::endl;
	delete catAnimal;
	std::cout << RESET KEYWORD_F "delete " CODE "dogAnimal;" OUTPUT_F << std::endl;
	delete dogAnimal;
	std::cout << RESET KEYWORD_F "delete " CODE "genericAnimal;" OUTPUT_F << std::endl;
	delete genericAnimal;
	std::cout << RESET KEYWORD_F "delete " CODE "wrongAnimal;" OUTPUT_F << std::endl;
	delete wrongAnimal;
	std::cout << RESET KEYWORD_F "delete " CODE "wrongCat;" OUTPUT_F << std::endl;
	delete wrongCat;
	std::cout << RESET << std::endl;

	std::cout << TITLE ">> Testing copy constructor: <<" RESET << std::endl;
	std::cout << CLASS_F "Cat" CODE " c;" OUTPUT_F << std::endl;
	Cat		c;
	std::cout << RESET CLASS_F "Animal" CODE " a = c;" OUTPUT_F << std::endl;
	Animal	a = c;
	std::cout << CODE "c." FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << c.getType() << CODE "\"" << std::endl;
	std::cout << CODE "a." FUNCTION_F "getType" CODE "() =>  \"" BR_BLUE << a.getType() << CODE "\"" << std::endl;
	std::cout << CODE "c." FUNCTION_F "makeSound" CODE "();" BR_BLUE << std::endl;
	c.makeSound();
	std::cout << CODE "a." FUNCTION_F "makeSound" CODE "();" BR_BLUE << std::endl;
	a.makeSound();
	std::cout << RESET COMMENT "// The type is copied correctly, but animal still makes the generic sound" RESET << std::endl;
	std::cout << RESET << std::endl;

	return 0;
}