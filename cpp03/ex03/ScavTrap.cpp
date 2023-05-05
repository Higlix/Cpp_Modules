#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    std::cout << "ScavTrap("<< this->getNAME() <<") constructor called !!!\n";
}

void ScavTrap::attack( const std::string& target )
{
    std::cout << "ScavTrap " << getNAME() << " attacks to " << target
    << " dealing " << getAD() << " damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << getNAME() << " is now in \"Gate keeper mode\"."
    << std::endl;
}

ScavTrap::~ScavTrap() 
{ std::cout << "ScavTrap(" << getNAME() << ") destructor called !!!" << std::endl; }