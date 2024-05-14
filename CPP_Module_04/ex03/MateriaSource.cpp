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
		// Why empty?
		// A MateriaSource doesn't know where it got its Materia from, it can't delete them
		// therefore it can't overwrite them with new ones
		// therefore, MateriaSource should not be able to be copied
	}
	return *this;
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
