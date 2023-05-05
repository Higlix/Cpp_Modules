#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap npc1("Mike");
    ClapTrap npc2("Leeya");

    npc1 = npc2;

    std::cout << "My name is " << npc1.get_name() << std::endl;
    npc1.attack(npc2.get_name());
    return (0);
}