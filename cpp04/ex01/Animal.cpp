#include "Animal.hpp"

Animal::Animal() : _type("Zoic")
{
	std::cout << "Animal" <<  " constructor called 1" << std::endl;
}

Animal::Animal(std::string type) : _type( type )
{
	std::cout << "Animal" << " constructor called 2" << std::endl;
}

Animal::Animal(const Animal &ref)
{
    std::cout << "Animal copy constructor called 3" << std::endl;
    *this = ref;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& ref )
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &ref ) {
        this->_type = ref._type;
    }
    return *this;
}

void Animal::makeSound( void ) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

std::string    Animal::getType( void ) const
{
    return this->_type;
}