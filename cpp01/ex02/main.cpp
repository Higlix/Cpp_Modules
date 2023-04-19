#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	(void )argc;
	(void )argv;

	std::string br = "HI THIS IS BRAIN";
	std::string &brREF = br;
	std::string *brPTR = &br;
	

	std::cout << "The memory address of the string variable: " << &br << std::endl;
	std::cout << "The memory address of stringPTR: " << &brPTR << std::endl;
	std::cout << "The memory address of stringREF: " << &brREF << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "The value of the string variable: " << br << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *brPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << brREF << std::endl << std::endl;

	std::cout << br << std::endl;
	return (0);
}