#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap npc1("Mikey");
    ScavTrap npc2("Leeya");

    npc1.attack(npc2.getNAME());
    npc2.takeDamage(npc1.getAD());
    npc2.beRepaired(npc1.getAD() / 2);
    npc2.guardGate();
    return (0);
}