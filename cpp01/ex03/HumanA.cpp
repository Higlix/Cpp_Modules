#include "Weapon.hpp"
#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon& weapon )
{
	this->weapon = &weapon;
	this->name = name;
}

HumanA::~HumanA() {}