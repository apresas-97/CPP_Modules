#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource & src )
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource( void )
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & other )
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if ( this != &other )
	{
		// for (int i = 0; i < 4; i++)
		// 	this->_learnedMaterias[i] = NULL;
		// for (int i = 0; i < 4; i++)
		// 	this->_learnedMaterias[i] = other._learnedMaterias[i]->clone();
	}
	return *this;
}

void	MateriaSource::printMaterias( void ) const
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "On slot [" << i << "]: ";
		if (this->_learnedMaterias[i])
			std::cout << "Type = " << this->_learnedMaterias[i]->getType() << std::endl;
		else
			std::cout << "No materia" << std::endl;
	}
}

void	MateriaSource::learnMateria( AMateria *materia )
{
	if (!materia)
	{
		std::cout << "MateriaSource cannot learn a non existent materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i] == NULL)
		{
			if (materia->setOwner("MateriaSource") == false)
			{
				std::cout << "MateriaSource can't learn the Materia because it's owned by " << materia->getOwner() << std::endl;
				return;
			}
			this->_learnedMaterias[i] = materia;
			std::cout << "MateriaSource learned a " << this->_learnedMaterias[i]->getType() << " materia" << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource cannot learn any more materias" << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i] && this->_learnedMaterias[i]->getType() == type)
		{
			std::cout << "MateriaSource is creating a " << type << " Materia" << std::endl;
			return this->_learnedMaterias[i]->clone();
		}
	}
	std::cout << "MateriaSource tried and failed to create a " << type << " Materia" << std::endl;
	return 0;
}
