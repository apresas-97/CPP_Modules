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
	const WrongAnimal* wrongA = new WrongCat();
	std::cout << std::endl;
	const WrongCat *wrongC = new WrongCat();
	std::cout << std::endl;


	std::cout << "Testing getType():" << std::endl;
	std::cout << "Animal* Dog = " << j->getType() << std::endl;
	std::cout << "Animal* Cat = " << i->getType() << std::endl;
	std::cout << "Animal* = " << meta->getType() << std::endl;
	std::cout << "WrongAnimal* Cat = " << wrongA->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing makeNoise():" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound(); // will output the typeless sound!
	wrongA->makeSound(); // will incorrectly output the typeless sound!
	wrongC->makeSound(); // will make a cat sound as it's of type WrongCat
	std::cout << std::endl;
	std::cout << "Deleting pointers:" << std::endl;
	std::cout << "----------" << std::endl;
	delete i;
	std::cout << "----------" << std::endl;
	delete j;
	std::cout << "----------" << std::endl;
	delete meta;
	std::cout << "----------" << std::endl;
	delete wrongA;
	std::cout << "----------" << std::endl;
	delete wrongC;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	std::cout << "Constructing Cat c:" << std::endl;
	Cat		c;
	std::cout << "----------" << std::endl;
	std::cout << "Assiging Animal a = c:" << std::endl;
	Animal	a = c;
	std::cout << "----------" << std::endl;
	std::cout << "c type = " << c.getType() << std::endl;
	std::cout << "a type = " << a.getType() << std::endl;
	std::cout << "----------" << std::endl;

	std::cout << "c.makeSound():" << std::endl;
	c.makeSound();
	std::cout << "a.makeSound():" << std::endl;
	a.makeSound();
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	return 0;
}