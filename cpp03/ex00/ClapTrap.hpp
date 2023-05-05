#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
private:
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

    std::string get_name();
};

#endif