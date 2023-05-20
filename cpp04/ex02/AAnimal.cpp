#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Zoic")
{
	std::cout << "AAnimal" <<  " constructor called 1" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type( type )
{
	std::cout << "AAnimal" << " constructor called 2" << std::endl;
}

AAnimal::AAnimal(const AAnimal &ref)
{
    std::cout << "AAnimal copy constructor called 3" << std::endl;
    *this = ref;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& ref )
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if ( this != &ref ) {
        this->_type = ref._type;
    }
    return *this;
}

std::string    AAnimal::getType( void ) const
{
    return this->_type;
}