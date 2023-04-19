#include "Zombie.hpp"

int main(int argc, char **argv)
{
	(void )argc;
	(void )argv;

	Zombie *horde;

	horde = zombieHorde(10, "Mikey");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}