#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <cstdlib>
# include <climits>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& rhs );
		ScalarConverter& operator=( const ScalarConverter& rhs );
		~ScalarConverter();

		static void	convert( std::string value );
};


#endif