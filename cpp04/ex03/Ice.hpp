#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
private:

public:
    Ice();
    ~Ice();

    AMateria *clone() const;
    void    use(ICharacter& Target);
};

#endif