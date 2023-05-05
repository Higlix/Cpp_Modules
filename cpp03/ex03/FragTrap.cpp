#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
    setHP(100);
    setEP(100);
    setAD(30);
    std::cout << "FragTrap("<< this->getNAME() <<") constructor called !!!\n";
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << getNAME() << " requests highest of fives" << std::endl;
}

FragTrap::~FragTrap()
{ std::cout << "FragTrap(" << getNAME() << ") destructor called !!!" << std::endl; }