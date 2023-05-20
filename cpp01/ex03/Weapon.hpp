# pragma once

#include <iostream>
#include <string>

class Weapon {

public:
	const std::string& get_type();
	void set_type( std::string _type );
	Weapon( std::string _type );
	~Weapon();
private:
	std::string _type;
};