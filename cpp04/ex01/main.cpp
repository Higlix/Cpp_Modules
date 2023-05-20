#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    // Animal *animal[10];

    // for (int i = 0; i < 10; i++)
    // {
    //     if (i < 5)
    //         animal[i] = new Dog;
    //     else
    //         animal[i] = new Cat;
    // }
    // for (int i = 0; i < 10; i++)
    //     delete animal[i];

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    return 0;
}