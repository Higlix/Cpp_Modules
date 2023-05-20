#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}

Brain::Brain(const Brain &ref)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain &ref)
{
    if (this != &ref)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = ref.ideas[i];
    }
    return *this;
}

