#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
	void    iter( T* array, int length, void (*increment)(T*))
	{
		for (int i = 0; i < length; i++)
		{
			increment(&array[i]);
		}
	}

#endif