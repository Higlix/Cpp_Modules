#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    // AAnimal *AAnimal[10];

    // for (int i = 0; i < 10; i++)
    // {
    //     if (i < 5)
    //         AAnimal[i] = new Dog;
    //     else
    //         AAnimal[i] = new Cat;
    // }
    // for (int i = 0; i < 10; i++)
    //     delete AAnimal[i];

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();


    /* This function creation of a instance of class AAnimal is not possible it is an abstract class */
    //const AAnimal some_random_animal = new AAnimal(); 


    delete j;
    delete i;

    const AAnimal *arr[4] = { new Dog(), new Cat(), new Dog(), new Cat() };

    for (int i = 0; i < 4; i++)
    {
        arr[i]->makeSound();
        delete arr[i];
    }

    return 0;
}