#ifndef CLASS_HPP
# define CLASS_HPP

class Class
{

private:

protected:

public:

	Class( void );
	Class( Class & src );
	Class & operator=( Class const & other );
	~Class( void );

};

#endif // CLASS_HPP