
#pragma once

#include <iostream>
#include <string>

class Zombie {

public:
	void announce( void );
	Zombie( std::string name );
	~Zombie();

private:
	std::string name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );