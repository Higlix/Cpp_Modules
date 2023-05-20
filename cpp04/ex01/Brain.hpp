#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &ref);
    Brain &operator=(const Brain &ref);
    ~Brain();

private:
    std::string ideas[100];
};

#endif