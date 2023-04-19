#include "Zombie.hpp"

int main(int argc, char **argv)
{
	(void )argc;
	(void )argv;
	Zombie mike("Mike");
	mike.announce();
	std::cout << "Mike was created in stack" << std::endl;
	Zombie *james = newZombie("James");
	james->announce();
	std::cout << "James was created in heap" << std::endl;
	std::cout << "We can call delete on James" << std::endl;
	delete james;
	std::cout << "Now it is time to call the randomChump" << std::endl;
	randomChump("RC");
	std::cout << "This instance lives in the function scope randomChump()" << std::endl;
	return (0);
}