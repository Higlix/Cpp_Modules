#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << this->_type << " constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat( void )
{
    std::cout << this->_type << " destructor called" << std::endl;
    delete this->brain;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}