# pragma once

#include "Weapon.hpp"

class HumanA {

public:
	Weapon *weapon;
	std::string name;
	void attack();
	HumanA( std::string name, Weapon& weapon );
	~HumanA();
private:

};