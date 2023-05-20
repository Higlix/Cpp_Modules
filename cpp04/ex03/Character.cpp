#include "Character.hpp"

Character::Character() : _name("DEFAULT_CHARACTER"), _inventory_size(4)
{
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < this->_inventory_size; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const std::string name) : _name(name), _inventory_size(4)
{
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < this->_inventory_size; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character &ref)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < this->_inventory_size; i++)
        this->_inventory[i] = ref._inventory[i];
}

Character& Character::operator=(const Character &ref)
{
    if (&ref != this)
    {
        for (int i = 0; i < this->_inventory_size; i++)
            this->_inventory[i] = ref._inventory[i];
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < this->_inventory_size; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (_inventory[idx] != NULL)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (_inventory[idx] != NULL)
        this->_inventory[idx]->use(target);
}