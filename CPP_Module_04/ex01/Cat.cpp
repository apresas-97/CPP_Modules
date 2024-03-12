#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructed" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	*this = src;
	std::cout << "Cat copy constructed" << std::endl;
}

Cat::~Cat( void )
{
	delete this->brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat &	Cat::operator=( Cat const & other )
{
	if ( this != &other )
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat: Meowwwwww" << std::endl;
}

void	Cat::addIdea( std::string idea )
{
	std::cout << "Cat had a new idea! \"" << idea << "\"" << std::endl;
	this->brain->addIdea(idea);
}

void	Cat::changeIdea( int index, std::string idea )
{
	if (index >= 100 || index < 0)
		return ;
	std::cout << "Cat changed his mind from:\n\"" << getIdea(index) << "\"\nTo\n\"" << idea << "\"" << std::endl;
	this->brain->changeIdea(index, idea);
}

std::string	Cat::getIdea( int index )
{
	return (this->brain->getIdea(index));
}
