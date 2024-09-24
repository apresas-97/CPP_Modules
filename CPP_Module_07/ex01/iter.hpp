#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template<typename T>
void	iter( T* array, size_t arrayLen, void (*f)( T & ) )
{
	if (!array)
		return ;
	for (size_t i = 0; i < arrayLen; i++)
		f(array[i]);
}

#endif // ITER_HPP