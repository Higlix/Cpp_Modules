#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:

	public:
		Serializer();
		Serializer( const Serializer& rhs );
		Serializer& operator=( const Serializer& rhs );
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif