#include "Weapon.hpp"
#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->get_type() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

HumanB::HumanB( std::string name )
{
	this->weapon = new Weapon("Unarmed");
	this->name = name;
}

HumanB::~HumanB() {}