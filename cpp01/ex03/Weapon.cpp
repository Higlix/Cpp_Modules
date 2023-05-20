#include "Weapon.hpp"
	
const std::string& Weapon::get_type()
{
	const std::string& ref = this->_type;
	return (ref);
}

void Weapon::set_type( std::string _type )
{
	this->_type = _type;
}

Weapon::Weapon( std::string _type )
{
	this->_type = _type;
}

Weapon::~Weapon() { std::cout << "Weapon Dest\n"; }