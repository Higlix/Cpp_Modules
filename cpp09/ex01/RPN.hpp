#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	public:
		RPN();
		RPN( const RPN& rhs );
		RPN& operator=( const RPN& rhs );
		~RPN();

		static int calculate( std::string rpns );
};

#endif