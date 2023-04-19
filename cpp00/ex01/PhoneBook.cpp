#include "PhoneBook.hpp"

std::string	get_string()
{
	std::string str;
    std::cin.clear();
    fflush(stdin);
    std::getline(std::cin, str);
	return (str);
}

void	shorten_string(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << str.substr(0, 10) << "|";
}

void	show_user_details(Contact con)
{
	std::cout 
		<< "First Name: " << con.first_name << std::endl
		<< "Last Name: " << con.last_name << std::endl
		<< "Nick Name: " << con.nick_name << std::endl
		<< "Phone Number: " << con.phone_number << std::endl
		<< "Darkest Secret: " << con.darkest_secret << std::endl;
}

void	PhoneBook::add_user()
{
	int	index;

	index = contact_count % 8;
	std::cout << "First Name: ";
	contacts[index].first_name = get_string();
	std::cout << "Last Name: ";
	contacts[index].last_name = get_string();
	std::cout << "Nick Name: ";
	contacts[index].nick_name = get_string();
	std::cout << "Phone Number: ";
	contacts[index].phone_number = get_string();
	std::cout << "Darkest Secret: ";
	contacts[index].darkest_secret = get_string();
	contact_count++;
}

void	PhoneBook::show_user()
{
	int index;

	if (contact_count == 0)
	{
		std::cout << "*** NO CONTACTS ADDED... YET ;) ***" << std::endl;
		return ;
	}
	std::cout << "|===================================|" << std::endl;
	std::cout << "||||   Name   | LastName | NickName |" << std::endl;
	std::cout << "|===================================|" << std::endl;
	for (int i = 0; i < contact_count && i < 8; i++)
	{
		std::cout << "|" << i + 1 << "-|";
		shorten_string(contacts[i].first_name);
		shorten_string(contacts[i].last_name);
		shorten_string(contacts[i].nick_name);
		std::cout << std::endl;
	}
	std::cout << "|===================================|" << std::endl;
	std::cout << "To show a user in detail please enter the index of the user if not enter (-1): ";
	std::cin >> index;
	index--;
	if (index > -1 && index < contact_count && index < 8)
		show_user_details(contacts[index]);
}