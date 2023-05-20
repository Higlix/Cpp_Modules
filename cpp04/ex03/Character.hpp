#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    AMateria *_inventory[4];
    std::string _name;
    int _inventory_size;

public:
    Character();
    Character(const std::string name);
    Character(const Character &ref);
    Character& operator=(const Character &ref);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif