#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
private: // go to line 15* you can just say "protected" lol
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;

public:
    ClapTrap( std::string name );
    ClapTrap( const ClapTrap &clap );
    ClapTrap &operator=( const ClapTrap &clap );
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // instead of all of this *go to line 7
    void    setHP(int HP);
    void    setEP(int EP);
    void    setAD(int AD);
    void    setNAME(int NAME);

    int    getHP();
    int    getEP();
    int    getAD();
    std::string    getNAME();
    
};

#endif