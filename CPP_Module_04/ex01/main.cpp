#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	int	animalCount = 42;
	Animal	*animals[animalCount];
	std::cout << "Constructing all animals:" << std::endl;
	for (int i = 0; i < animalCount; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Deleting animals array:" << std::endl;
	for (int i = 0; i < animalCount; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "Testing that copies are NOT shallow:" << std::endl;
	Dog d1;
	d1.addIdea("I'm hungry");
	std::cout << std::endl;
	Dog d2 = d1;
	d1.changeIdea(0, "I wanna play");
	std::cout << std::endl;

	std::cout << "Dog 1's idea[0] = \"" << d1.getIdea(0) << "\"" << std::endl;
	std::cout << "Dog 2's idea[0] = \"" << d2.getIdea(0) << "\"" << std::endl;

	std::cout << std::endl;
	return 0;
}