#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
// overriding functions

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    DiamondTrap();
    std::string name;

public:
    DiamondTrap( std::string name );
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI();
};

#endif 