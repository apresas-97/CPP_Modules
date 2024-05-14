#include <iostream>
#include <string>

#include "AAnimal.hpp"
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
	std::cout << TITLE ">> Initialising variables: <<" << std::endl;
	int dogCount = 2;
	std::cout << CODE "int dogCount = " << dogCount << RESET << std::endl;
	int	catCount = 2;
	std::cout << CODE "int dogCount = " << catCount << RESET << std::endl;
	std::cout << CODE "Dog *dogs[ dogCount ];" RESET << std::endl;
	Dog	*dogs[dogCount];
	std::cout << CODE "Cat *cats[ catCount ];" RESET << std::endl;
	Cat	*cats[catCount];
	std::cout << std::endl;

	std::cout << TITLE ">> Constructing all animals: <<" RESET << std::endl;
	for (int i = 0; i < dogCount; i++)
	{
		std::cout << CODE "\ndogs[ " BOLD YELLOW << i << CODE " ]" CODE " = " KEYWORD_F "new " DOG_F "Dog()" CODE ";" COMMENT " // Allocate a new Dog" OUTPUT_F << std::endl;
		dogs[i] = new Dog();
	}
	for (int i = 0; i < catCount; i++)
	{
		std::cout << CODE "\ncats[ " BOLD YELLOW << i << CODE " ]" CODE " = " KEYWORD_F "new " CAT_F "Cat()" CODE ";" COMMENT " // Allocate a new Cat" OUTPUT_F << std::endl;
		cats[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << TITLE ">> Deleting Dogs array: <<" RESET << std::endl;
	for (int i = 0; i < dogCount; i++)
	{
		std::cout << CODE KEYWORD_F "\ndelete " BR_CYAN "dogs[ " BOLD YELLOW << i << CODE BR_CYAN " ]" CODE ";" COMMENT " // Delete the allocated object in dogs[ " << i << " ]" OUTPUT_F << std::endl;
		delete dogs[i];
	}
	std::cout << RESET BOLD GREEN "Succesfully deallocated and destroyed all dogs" RESET << std::endl;
	std::cout << std::endl;
	std::cout << TITLE ">> Deleting Cats array: <<" RESET << std::endl;
	for (int i = 0; i < catCount; i++)
	{
		std::cout << CODE KEYWORD_F "\ndelete " BR_CYAN "cats[ " BOLD YELLOW << i << CODE BR_CYAN " ]" CODE ";" COMMENT " // Delete the allocated object in cats[ " << i << " ]" OUTPUT_F << std::endl;
		delete cats[i];
	}
	std::cout << RESET BOLD GREEN "Succesfully deallocated and destroyed all cats" RESET << std::endl;
	std::cout << std::endl;

	std::cout << TITLE ">> Constructing Dog and Cat objects in AAnimal* <<\n" RESET << std::endl;
	std::cout << CODE "AAnimal *animalDog = " KEYWORD_F "new " DOG_F "Dog()" CODE ";" COMMENT " // Allocate a new Dog in a AAnimal*" OUTPUT_F << std::endl;
	AAnimal*	animalDog = new Dog();
	std::cout << CODE "AAnimal *animalCat = " KEYWORD_F "new " CAT_F "Cat()" CODE ";" COMMENT " // Allocate a new Cat in a AAnimal*" OUTPUT_F << std::endl;
	AAnimal*	animalCat = new Cat();
	std::cout << std::endl;

	std::cout << CODE BR_CYAN "animalCat->makeSound();" RESET << std::endl;
	animalCat->makeSound();
	std::cout << CODE BR_CYAN "animalDog->getType()" CODE " = " << animalDog->getType() << RESET << std::endl;
	std::cout << std::endl;

	// Uncomment this to verify that an Animal object cannot be constructed on its own
	// AAnimal animalA = animalCat;
	// AAnimal animalB;

	std::cout << CODE KEYWORD_F "delete " BR_CYAN "animalDog;" COMMENT " // Delete the allocated Dog in this AAnimal*" OUTPUT_F << std::endl;
	delete animalDog;
	std::cout << CODE KEYWORD_F "delete " BR_CYAN "animalCat;" COMMENT " // Delete the allocated Cat in this AAnimal*" OUTPUT_F << std::endl;
	delete animalCat;
	std::cout << RESET << std::endl;

	return 0;
}