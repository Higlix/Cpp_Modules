#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) {

    this->name = name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap("<< name << ") constructor called !!!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &clap )
{
    this->name = clap.name;
    this->hit_point = clap.hit_point;
    this->energy_point = clap.energy_point;
    this->attack_damage = clap.attack_damage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &clap )
{
    this->name = clap.name;
    this->hit_point = clap.hit_point;
    this->energy_point = clap.energy_point;
    this->attack_damage = clap.attack_damage;
    return (*this);
}

void    ClapTrap::attack( const std::string &target )
{
    if (energy_point == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
    << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point--;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (energy_point == 0)
        return ;
    this->hit_point += amount;
    this->energy_point--;
    std::cout << this->name << " is getting repaired for " << amount << " hit points!"
    << std::endl;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (energy_point == 0)
        return ;
    this->hit_point -= amount;
    std::cout << this->name << " got attacked for " << amount << " damage!" << std::endl;
}

ClapTrap::~ClapTrap() {

    std::cout << "ClapTrap(" << name << ") destructor called !!!" << std::endl;
}

void    ClapTrap::setHP(int HP) {
    this->hit_point = HP;
}
void    ClapTrap::setEP(int EP) {
    this->energy_point = EP;
}
void    ClapTrap::setAD(int AD) {
    this->attack_damage = AD;
}
void    ClapTrap::setNAME(int NAME) {
    this->name = NAME;
}

int    ClapTrap::getHP() {
    return (this->hit_point);
}
int    ClapTrap::getEP() {
    return (this->energy_point);
}
int    ClapTrap::getAD() {
    return (this->attack_damage);
}
std::string    ClapTrap::getNAME() {
    return (this->name);
}