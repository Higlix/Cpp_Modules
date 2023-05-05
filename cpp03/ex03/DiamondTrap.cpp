#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name )
{
    this->name = name;
    this->ClapTrap::setNAME(name + "_clap_name");

    FragTrap::setHP(100);
    ScavTrap::setEP(50);
    FragTrap::setAD(30);
    std::cout << "DiamondTrap("<< this->getNAME() <<") constructor called !!!\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << name << " also know as " << ClapTrap::getNAME() << std::endl;
}

DiamondTrap::~DiamondTrap()
{ std::cout << "DiamondTrap(" << getNAME() << ") destructor called !!!" << std::endl; }