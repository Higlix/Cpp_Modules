#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void)
{
    Character ply("Player");
    Character ene("Enemy");
    Ice ice;
    Cure cure;

    ply.equip(&ice);
    ply.use(0, ene);
    ene.equip(&cure);
    ene.use(0, ply);

    return (0);
}