#include "Harl.hpp"

void	Harl::debug( void )
{
    std::cout << "\"DEBUG\": I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
    std::cout << "I really do!\n" << std::endl;
}

void	Harl::info( void )
{
    std::cout << "\"INFO\": I cannot believe adding extra bacon costs more money. You didn't put\n";
    std::cout << "enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning( void )
{
    std::cout << "\"WARNING\": I think I deserve to have some extra bacon for free. I've been coming for\n";
    std::cout << "years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error( void )
{
    std::cout << "\"ERROR\": This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain( std::string level )
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int i = 0;

    for (i = 0; i < 4; i++)
        if (!level.compare(levels[i]))
            break ;

    switch (i)
    {
        case 0:
            this->debug();
            this->info();
            this->warning();
            this->error();
            break ;
        case 1:
            this->info();
            this->warning();
            this->error();
            break ;
        case 2:
            this->warning();
            this->error();
            break ;
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}