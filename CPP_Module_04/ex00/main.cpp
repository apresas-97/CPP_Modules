#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	std::cout << "Constructing:" << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const WrongAnimal* wi = new WrongCat();
	std::cout << std::endl;


	std::cout << "Testing getType():" << std::endl;
	std::cout << "Animal* Dog = " << j->getType() << std::endl;
	std::cout << "Animal* Cat = " << i->getType() << std::endl;
	std::cout << "Animal* = " << meta->getType() << std::endl;
	std::cout << "WrongAnimal* Cat = " << wi->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing makeNoise():" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound(); // will output the typeless sound!
	wi->makeSound(); // will incorrectly output the typeless sound!
	std::cout << std::endl;
	std::cout << "Deleting pointers:" << std::endl;
	delete i;
	delete j;
	delete meta;
	delete wi;
	std::cout << std::endl;

	std::cout << "Constructing Cat c:" << std::endl;
	Cat		c;
	std::cout << "Assiging Animal a = c:" << std::endl;
	Animal	a = c;
	std::cout << std::endl;
	std::cout << "c type = " << c.getType() << std::endl;
	std::cout << "a type = " << a.getType() << std::endl;
	std::cout << std::endl;

	std::cout << "c.makeSound():" << std::endl;
	c.makeSound();
	std::cout << "a.makeSound():" << std::endl;
	a.makeSound();
	std::cout << std::endl;


	return 0;
}