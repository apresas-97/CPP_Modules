#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstring>

template<typename T = int >
class Array
{
	public:
		Array( void );
		Array( unsigned int n );
		Array( Array const & src );
		~Array();
		Array &		operator=( Array const & rhs );
		T &			operator[]( unsigned int i );
		const T &	operator[]( unsigned int i ) const;

		unsigned int	size( void ) const;
	
	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	private:
		unsigned int	_n;
		T*				_array;
};

template <typename T>
Array<T>::Array( void ) : _n(0), _array(NULL)
{
	// std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array( unsigned int n ) : _n(n)
{
	// std::cout << "Array parameterized constructor called" << std::endl;
	if (this->_n == 0)
	{
		this->_array = NULL;
		return ;
	}
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = T();
}

template<typename T>
Array<T>::Array( Array const & src ) : _n(0), _array(NULL)
{
	// std::cout << "Array copy constructor called" << std::endl;
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	// std::cout << "Array destructor called" << std::endl;
	delete [] this->_array;
}

template<typename T>
Array<T> & Array<T>::operator=( Array const & rhs )
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		if (this->_array)
			delete [] this->_array;
		if (this->_n == 0)
		{
			this->_array = NULL;
			return *this;
		}
		this->_array = new T[this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
			this->_array[i] = rhs._array[i];
	}
	return *this;
}

template<typename T>
T &	Array<T>::operator[]( unsigned int i )
{
	if (i >= this->_n)
		throw Array<T>::IndexOutOfRangeException();
	return this->_array[i];
}


template<typename T>
const T &	Array<T>::operator[]( unsigned int i ) const
{
	if (i >= this->_n)
		throw Array<T>::IndexOutOfRangeException();
	return this->_array[i];
}

template<typename T>
std::ostream &	operator<<( std::ostream & out, Array<T> const & rhs )
{
	if (rhs.size() == 0)
	{
		out << "(null)";
		return out;
	}
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		out << rhs[i];
		if (i < rhs.size() - 1)
			out << ", ";
	}
	return out;
}

template<>
std::ostream &	operator<<( std::ostream & out, Array<bool> const & rhs )
{
	if (rhs.size() == 0)
	{
		out << "(null)";
		return out;
	}
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		if (rhs[i])
			out << "true";
		else
			out << "false";
		if (i < rhs.size() - 1)
			out << ", ";
	}
	return out;
}

template<>
std::ostream &	operator<<( std::ostream & out, Array<char> const & rhs )
{
	if (rhs.size() == 0)
	{
		return out;
	}
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		out << rhs[i];
	}
	return out;
}

template<typename T>
unsigned int	Array<T>::size( void ) const
{
	return this->_n;
}

// Exceptions
template<typename T>
const char* Array<T>::IndexOutOfRangeException::what() const throw()
{
	return "Index out of range";
}

#endif // ARRAY_HPP