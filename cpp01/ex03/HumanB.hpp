# pragma once

#include "Weapon.hpp"

class HumanB {

public:
	Weapon *weapon;
	std::string name;
	void attack();
	void setWeapon(Weapon& weapon);
	HumanB( std::string name );
	~HumanB();
private:

};