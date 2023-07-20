#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		std::string _name;
	
	public:
		Data();
		Data( const Data& rhs );
		Data& operator=( const Data& rhs );
		~Data();

		std::string getName() const;
};

#endif