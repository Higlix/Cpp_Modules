#include <iostream>

void	greet_user()
{
	std::cout << "|-------------------------------|" << std::endl;
	std::cout << "|Hello Phone User Welcome to 80s|" << std::endl;
	std::cout << "|-------------------------------|" << std::endl << std::endl;
}

void	show_options()
{
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "| 1-Enter \"ADD\" to add a new user       |" << std::endl;
	std::cout << "| 2-Enter \"SEARCH\" to search for a user |" << std::endl;
	std::cout << "| 3-Enter \"EXIT\" to exit the phonebook  |" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}

int	take_input()
{
	std::string	input;

	std::cin >> input;
	if (input.compare("ADD") == 0 || input.compare("1") == 0)
		return (1);
	else if (input.compare("SEARCH") == 0 || input.compare("2") == 0)
		return (2);
	else if (input.compare("EXIT") == 0 || input.compare("3") == 0)
		return (3);
	return (-1);
}