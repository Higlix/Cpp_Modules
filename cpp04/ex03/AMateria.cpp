#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria constructor called" << std::endl;
    this->_type = "_type";
}

AMateria::AMateria(const AMateria &ref)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = ref;
}

AMateria::AMateria(const std::string &type) : _type(type) {/* */}

AMateria &AMateria::operator=(const AMateria &ref)
{
    if (&ref != this)
    {
        this->_type = ref._type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

void    AMateria::use( ICharacter& target )
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
