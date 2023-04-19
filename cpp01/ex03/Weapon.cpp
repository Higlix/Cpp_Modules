#include "Weapon.hpp"
	
const std::string& Weapon::getType()
{
	const std::string& ref = this->type;
	return (ref);
}

void Weapon::setType( std::string type )
{
	this->type = type;
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}

Weapon::~Weapon() { std::cout << "Weapon Dest\n"; }