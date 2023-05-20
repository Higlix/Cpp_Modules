#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    std::cout << this->_type << " constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog(void)
{
    std::cout << this->_type << " destructor called" << std::endl;
    delete this->brain;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
}