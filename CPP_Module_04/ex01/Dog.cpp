#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal()
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
	if ( this != &other )
	{
		this->type = other.type;
		// if (this->brain)
			// delete this->brain;
		// if (other.brain)
			this->brain = new Brain(*other.brain);
		// else
			// this->brain = NULL;
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

