#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else if (argc == 1)
		std::cout << "NOT ENOUGH ARGUMENTS" << std::endl;
	else
		std::cout << "TOO MANY ARGUMENTS" << std::endl;
	return (0);
}