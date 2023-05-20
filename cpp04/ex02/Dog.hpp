#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;

public:
    Dog(void);
    ~Dog(void);

    void   makeSound( void ) const;
};

#endif