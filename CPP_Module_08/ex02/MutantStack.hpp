#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack( void );
		MutantStack( MutantStack const & src );
		~MutantStack();
		MutantStack &	operator=( MutantStack const & rhs );

	typedef typename std::stack<T, Container>::container_type::iterator				iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator				begin( void )
	{
		return this->c.begin();
	}
	iterator				end( void )
	{
		return this->c.end();
	}

	const_iterator			begin( void ) const
	{
		return this->c.begin();
	}
	const_iterator			end( void ) const
	{
		return this->c.end();
	}

	reverse_iterator		rbegin( void )
	{
		return this->c.rbegin();
	}
	reverse_iterator		rend( void )
	{
		return this->c.rend();
	}

	const_reverse_iterator	rbegin( void ) const
	{
		return this->c.rbegin();
	}
	const_reverse_iterator	rend( void ) const
	{
		return this->c.rend();
	}

};

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( void ) : std::stack<T, Container>()
{

}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( MutantStack const & src ) : std::stack<T, Container>(src)
{
	*this = src;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{

}

template<typename T, typename Container>
MutantStack<T, Container> &	MutantStack<T, Container>::operator=( MutantStack const & rhs )
{
	std::stack<T, Container>::operator=(rhs);
	return *this;
}

#endif // MUTANTSTACK_HPP