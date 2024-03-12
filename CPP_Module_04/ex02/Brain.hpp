#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{

private:
	std::string	ideas[100];
	int	_index;

public:

	Brain( void );
	Brain( Brain const & src );
	~Brain( void );
	Brain & operator=( Brain const & other );

	void		addIdea( std::string idea );
	void		changeIdea( int index, std::string idea );
	std::string	getIdea( int index );

};

#endif // BRAIN_HPP
