#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

# define FOUND 1

class ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("ValueNotFound");
		}
};

template<typename T>
	void	easyfind(T container, int toFind)
	{
		typename T::iterator start = container.begin();
		typename T::iterator end = container.end();

		while (start != end)
		{
			if (*start == toFind)
			{
				std::cout << "ValueFound" << std::endl;
				return ;
			}
			start++;
		}
		throw(ValueNotFound());
		// if ( std::find(container.begin(), container.end(), toFind) != container.end() )
		// 	std::cout << "ValueFound" << std::endl;
		// else	
		// 	throw(ValueNotFound());
	}


#endif