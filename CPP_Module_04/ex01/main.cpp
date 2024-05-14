#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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
// #define BR_BLUE "\033[94m" // Unused
#define BR_MAGENTA "\033[95m"
#define BR_CYAN "\033[96m"
#define BR_WHITE "\033[97m"
// #define B_YELLOW BOLD YELLOW // Unused
#define COMMENT ITALIC GREEN
#define TITLE RESET BOLD CYAN
#define CODE RESET ITALIC BR_WHITE
#define DOG_F RESET BOLD BR_RED
#define CAT_F RESET BOLD YELLOW
#define OUTPUT_F RESET DIM
#define KEYWORD_F BR_MAGENTA

int	main( void )
{
	std::cout << TITLE ">> Initialising variables <<" << std::endl;
	int	animalCount = 4; // Feel free to change this value
	std::cout << CODE "int	animalCount = " << animalCount << ";" << std::endl;
	if (animalCount > 1000)
	{
		std::cout << BR_RED "\nI'm not risking my program crashing with that large of an animalCount" RESET << std::endl;
		return 1;
	}
	Animal	*animals[animalCount];
	std::cout << CODE "Animal	*animals[ animalCount ];" << std::endl;
	std::cout << std::endl;


	std::cout << TITLE ">> Constructing all animals: (half " DOG_F "Dog" TITLE " and half " CAT_F "Cat" TITLE  ") <<" RESET << std::endl;
	for (int i = 0; i < animalCount; i++)
	{
		if (i % 2)
		{
			std::cout << CODE "\nanimals[ " BOLD YELLOW << i << CODE " ]" CODE " = " KEYWORD_F "new " DOG_F "Dog()" CODE ";" COMMENT " // Allocate a new Dog object in animals[ " << i << " ]" OUTPUT_F << std::endl;
			animals[i] = new Dog();
		}
		else
		{
			std::cout << CODE "\nanimals[ " BOLD YELLOW << i << CODE " ]" CODE " = " KEYWORD_F "new " CAT_F "Cat()" CODE ";" COMMENT " // Allocate a new Cat object in animals[ " << i << " ]" OUTPUT_F << std::endl;
			animals[i] = new Cat();
		}
	}
	std::cout << std::endl;
	std::cout << RESET BOLD GREEN "Succesfully created " << animalCount << " animals, " << animalCount / 2 + animalCount % 2 << " Cats and " << animalCount / 2 << " Dogs" RESET << std::endl;
	std::cout << std::endl;

	std::cout << TITLE ">> Testing that copies are NOT shallow: <<" RESET << std::endl;
	std::cout << CODE "Dog d1;" COMMENT" // Construct a Dog \"d1\" with the default constructor" << OUTPUT_F << std::endl;
	Dog d1;
	std::cout << std::endl;
	std::cout << CODE "d1.addIdea(" BOLD BR_MAGENTA "\"I'm hungry\"" CODE "); "  COMMENT "// Store a new idea in d1's brain" << OUTPUT_F << std::endl;
	d1.addIdea("I'm hungry"); // We add an idea to d1.brain.ideas[0]
	std::cout << std::endl;
	std::cout << CODE "Dog d2 = d1; " COMMENT "// Construct a new Dog \"d2\", copy of d1, with operator=" OUTPUT_F << std::endl;
	Dog d2 = d1;
	std::cout << std::endl;
	std::cout << CODE "Dog d3(" BR_CYAN "d1" RESET "); " COMMENT "// Construct a new Dog \"d3\", copy of d1, with copy constructor" OUTPUT_F << std::endl;
	Dog d3(d1);
	std::cout << std::endl;

	std::cout << RESET BOLD "Values of brain->ideas[0] for dogs d1, d2 and d3" RESET << std::endl;
	std::cout << CODE "d1.brain->ideas[0] = " RESET BR_RED "\"" << d1.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d2.brain->ideas[0] = " RESET BR_RED "\"" << d2.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d3.brain->ideas[0] = " RESET BR_RED "\"" << d3.getIdea(0) << "\"" RESET << std::endl;
	std::cout << std::endl;

	std::cout << CODE "d1.changeIdea(" BOLD CYAN "0" CODE ", " BOLD BR_MAGENTA "\"I wanna play\"" CODE "); " COMMENT "// Change d1's idea in index [ 0 ]" OUTPUT_F << std::endl;
	d1.changeIdea(0, "I wanna play");
	std::cout << std::endl;

	std::cout << RESET BOLD "Values of brain->ideas[0] for dogs d1, d2 and d3" RESET << std::endl;
	std::cout << CODE "d1.brain->ideas[0] = " RESET BR_CYAN "\"" << d1.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d2.brain->ideas[0] = " RESET BR_RED "\"" << d2.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d3.brain->ideas[0] = " RESET BR_RED "\"" << d3.getIdea(0) << "\"" RESET << std::endl;
	std::cout << std::endl;

	std::cout << CODE "d2.changeIdea(" BOLD CYAN "0" CODE ", " BOLD BR_MAGENTA "\"I'm sleepy\"" CODE "); " COMMENT "// Change d2's idea in index [ 0 ]" OUTPUT_F << std::endl;
	d2.changeIdea(0, "I'm sleepy");
	std::cout << std::endl;

	std::cout << RESET BOLD "Values of brain->ideas[0] for dogs d1, d2 and d3" RESET << std::endl;
	std::cout << CODE "d1.brain->ideas[0] = " RESET BR_CYAN "\"" << d1.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d2.brain->ideas[0] = " RESET BR_GREEN "\"" << d2.getIdea(0) << "\"" RESET << std::endl;
	std::cout << CODE "d3.brain->ideas[0] = " RESET BR_RED "\"" << d3.getIdea(0) << "\"" RESET << std::endl;
	// This shows that d1.brain.ideas[0] and d2.brain.ideas[0] are not the same
	std::cout << std::endl;
	std::cout << RESET BOLD GREEN "This shows that d2 and d3 are DEEP copies of d1, not SHALLOW" RESET << std::endl;

	std::cout << std::endl;
	std::cout << TITLE ">> Deleting animals array: (directly as Animals) <<" RESET << std::endl;
	for (int i = 0; i < animalCount; i++)
	{
		std::cout << CODE KEYWORD_F "\ndelete " BR_CYAN "animals[ " BOLD YELLOW << i << CODE BR_CYAN " ]" CODE ";" COMMENT " // Delete the allocated object in animals[ " << i << " ]" OUTPUT_F << std::endl;
		delete animals[i];
	}
	std::cout << std::endl;
	std::cout << RESET BOLD GREEN "Succesfully deallocated and destroyed all animals as Animals" RESET << std::endl;
	std::cout << std::endl;

	return 0;
}