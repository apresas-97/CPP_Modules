#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog( Dog const & src ) : AAnimal(src)
{
	*this = src;
	std::cout << "Dog copy constructed" << std::endl;
}

Dog::~Dog( void )
{
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog &	Dog::operator=( Dog const & other )
{
	std::cout << "Dog operator = called" << std::endl;
	if ( this != &other )
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog: Bark! Bark!" << std::endl;
}

void	Dog::addIdea( std::string idea )
{
	std::cout << "Dog had a new idea! \"" << idea << "\"" << std::endl;
	this->brain->addIdea(idea);
}

void	Dog::changeIdea( int index, std::string idea )
{
	if (index >= 100 || index < 0)
		return ;
	std::cout << "Dog changed his mind from:\n\"" << getIdea(index) << "\"\nTo\n\"" << idea << "\"" << std::endl;
	this->brain->changeIdea(index, idea);
}

std::string	Dog::getIdea( int index )
{
	return (this->brain->getIdea(index));
}

